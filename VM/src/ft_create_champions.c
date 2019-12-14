/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_champions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:02:54 by ohachim           #+#    #+#             */
/*   Updated: 2019/12/14 04:11:04 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

static int	ft_dash_n_value(char *n_string)
{
	int	cn;
	
	cn = 0;
	while (n_string[cn])
	{
		if (!ft_isdigit(n_string[cn]))
			return (0);
		cn++;
	}
	return (ft_atoi(n_string));
}

static int	ft_get_champion_index(int i, char **argv, t_global *global_data)
{
	int	n_value;

	n_value = 0;
	if (i >= 2)
	{
		if (ft_strequ(argv[i - 2], "-n"))
		{
			n_value = ft_dash_n_value(argv[i - 1]);
			if (n_value > 0 && n_value <= MAX_PLAYERS)
				return (n_value - 1);
		}
	}
	i = 0;
	while (global_data->champions[i].name != NULL && i < global_data->champion_count)
		i++;
	return (i);
}

static void	ft_assign_global_champion(char **argv, t_global *global_data, int wn)
{
	int	index;
	int	i;
	char	*temp;

	i = 0;
	index = ft_get_champion_index(wn, argv, global_data);
	if (global_data->champions[index].name == NULL)
		global_data->champions[index].name = argv[wn];
	else
	{
		temp = global_data->champions[index].name;
		global_data->champions[index].name = argv[wn];
		while (i < global_data->champion_count)
		{
			if (global_data->champions[i].name == NULL)
			{
				global_data->champions[i].name = temp;
				break ;
			}
			i++;
		}
	}
}

static void	ft_fill_champions(char **argv, t_global *global_data)
{
	int	wn;

	wn = 1;
	while (argv[wn])
	{
		if (ft_check_cor_extension(argv[wn]))
			ft_assign_global_champion(argv, global_data, wn);
		wn++;
	}
}

void	ft_create_champions(t_global *global_data, char **argv)
{
	int	i;

	i = 0;
	if ((global_data->champion_count = ft_count_champions(argv)) < 1)
	{
		ft_printf("Error: 0 Champions\n");
		exit(0);
	}
	ft_printf("Number of champions is ==> %d\n",
			global_data->champion_count);
	if (!(global_data->champions = (t_champion*)malloc(sizeof(t_champion)
					* global_data->champion_count + 1)))
	{
		ft_printf("Error: malloc fail\n");
		exit(0);
	}
	while (i <= global_data->champion_count)
	{
		global_data->champions[i].name = NULL;
		i++;		
	}
	ft_fill_champions(argv, global_data);
	i = 0;
}
