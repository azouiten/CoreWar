/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_champions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:02:54 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/10 05:22:33 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

static void	ft_init_champions(t_global *global_data)
{
	int	i;

	i = 0;
	while (i < global_data->champion_count)
	{
		global_data->champions[i].name = NULL;
		global_data->champions[i].comment = NULL;
		global_data->champions[i].byte_name = NULL;
		global_data->champions[i].exec_code = NULL;
		global_data->champions[i].validity = 1;
		global_data->champions[i].hex_code_size = 0;
		global_data->champions[i].number = i;
		global_data->champions[i].argn = -1;
		global_data->champions[i].fd = -1;
		global_data->champions[i].starting_point = -1;
		i++;
	}
}

void		ft_create_champions(t_global *global_data, char **argv)
{
	if (!(global_data->champion_count = ft_count_champions(argv)))
		ft_manage_error(global_data, ZERO_CHAMPION, -1, 1);
	else if (global_data->champion_count > MAX_PLAYERS)
		ft_manage_error(global_data, TOO_MANY_PLAYERS, -1, 1);
	if (!(global_data->champions = (t_champion*)malloc(sizeof(t_champion)
					* global_data->champion_count)))
		ft_manage_error(global_data, MALLOC_FAIL, -1, 1);
	ft_init_champions(global_data);
	ft_fill_champions(argv, global_data);
}
