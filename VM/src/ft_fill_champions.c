/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_champions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 06:37:36 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/04 23:03:30 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

static int		ft_dash_n_value(char *n_string)
{
	int			cn;

	cn = 0;
	while (n_string[cn])
	{
		if (!ft_isdigit(n_string[cn]))
			return (0);
		cn++;
	}
	return (ft_atoi(n_string));
}

static int		ft_get_champion_index(int i, char **argv,
		t_global *global_data, int time)
{
	int			n_value;

	n_value = 100;
	if (i >= 3)
	{
		if (ft_strequ(argv[i - 2], "-n"))
		{
			n_value = ft_dash_n_value(argv[i - 1]);
			if (n_value > 0 && n_value <= MAX_PLAYERS
					&& global_data->champions[n_value - 1].name == NULL)
				return (n_value - 1);
		}
	}
	i = 0;
	if ((n_value > MAX_PLAYERS
				|| global_data->champions[n_value - 1].name)
			&& !time)
		return (-1);
	while (global_data->champions[i].name != NULL
			&& i < global_data->champion_count)
		i++;
	return (i);
}

static void		ft_assign_global_champion(char **argv, t_global *global_data,
		int wn, int time)
{
	int			index;
	int			i;
	char		*temp;

	i = 0;
	index = ft_get_champion_index(wn, argv, global_data, time);
	if (index == -1)
		return ;
	global_data->champions[index].name = argv[wn];
	global_data->champions[index].argn = wn;
}

static int		ft_assigned(char **argv, t_global *global_data, int wn)
{
	int			i;

	i = 0;
	while (i < global_data->champion_count)
	{
		if (ft_strequ(argv[wn], global_data->champions[i].name)
				&& global_data->champions[i].argn == wn)
			return (1);
		i++;
	}
	return (0);
}

void			ft_fill_champions(char **argv, t_global *global_data)
{
	int			wn;

	wn = 3;
	while (argv[wn])
	{
		if (ft_check_cor_extension(argv[wn])
				&& ft_strequ(argv[wn - 2], "-n"))
			ft_assign_global_champion(argv, global_data, wn, 0);
		wn++;
	}
	wn = 1;
	while (argv[wn])
	{
		if (ft_check_cor_extension(argv[wn]))
			if (!ft_assigned(argv, global_data, wn))
				ft_assign_global_champion(argv, global_data, wn, 1);
		wn++;
	}
}
