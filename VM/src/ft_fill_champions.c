/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_champions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 22:00:25 by magoumi           #+#    #+#             */
/*   Updated: 2020/02/18 23:59:25 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

int			ft_dash_n_value(char *n_string)
{
	int	i;

	i = 0;
	while (n_string[i])
	{
		if (!ft_isdigit(n_string[i]))
			return (0);
		i++;
	}
	return (ft_atoi(n_string));
}

int			ft_get_champion_index(int argn, t_global *data, char **argv,
			int time)
{
	int	n_value;

	n_value = 100;
	if (argn >= 3)
	{
		if (ft_strequ(argv[argn - 2], "-n"))
		{
			n_value = ft_dash_n_value(argv[argn - 1]);
			if (n_value > 0 && n_value <= MAX_PLAYERS
					&& data->champions[n_value - 1].name == NULL)
				return (n_value - 1);
		}
	}
	argn = 0;
	if ((n_value > MAX_PLAYERS
				|| data->champions[n_value - 1].name)
			&& !time)
		return (-1);
	while (data->champions[argn].name != NULL
			&& argn < data->champion_count)
		argn++;
	return (argn);
}

void		ft_assign_global_champion(char **argv, t_global *data,
			int argn, int time)
{
	int	index;

	index = ft_get_champion_index(argn, data, argv, time);
	if (index == -1)
		return ;
	data->champions[index].name = argv[argn];
	data->champions[index].argn = argn;
}

int		ft_assigned(char **argv, t_global *data, int wn)
{
	int			i;

	i = 0;
	while (i < data->champion_count)
	{
		if (ft_strequ(argv[wn], data->champions[i].name)
				&& data->champions[i].argn == wn)
			return (1);
		i++;
	}
	return (0);
}

void	ft_fill_champions(t_global *data, char **argv)
{
	size_t	argn;

	argn = 3;
	while (argv[argn])
	{
		if (ft_check_cor_extension(argv[argn]) &&
			ft_strequ(argv[argn - 2], "-n"))
			ft_assign_global_champion(argv, data, argn, 0);
		argn++;
	}
	argn = 1;
	while (argv[argn])
	{
		if (ft_check_cor_extension(argv[argn]))
			if (!ft_assigned(argv, data, argn))
				ft_assign_global_champion(argv, data, argn, 1);
		argn++;
	}
}
