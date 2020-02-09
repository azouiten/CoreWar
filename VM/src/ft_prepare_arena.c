/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_arena.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 14:23:25 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/09 08:14:47 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

static void	ft_get_starting_points(t_global *global_data)
{
	int		step;
	int		i;
	int		checked;
	int		mem_point;

	i = 0;
	mem_point = 0;
	checked = 0;
	step = MEM_SIZE / global_data->valid_champions;
	while (checked < global_data->valid_champions)
	{
		while ((i < global_data->champion_count
		&& !global_data->champions[i].validity)
		|| global_data->champions[i].starting_point != -1)
			i++;
		global_data->champions[i].starting_point = mem_point;
		mem_point = mem_point + step;
		checked++;
	}
	global_data->last_live_player = global_data->champions[i];
}

static void	ft_get_valid_champions_count(t_global *global_data)
{
	int		i;

	i = 0;
	while (i < global_data->champion_count)
	{
		if (global_data->champions[i].validity)
			global_data->valid_champions++;
		i++;
	}
	if (!(global_data->valid_champions))
		ft_manage_error(global_data, ZERO_VALID_CHAMPION, -1, 1);
}

void	ft_prepare_arena(t_global *global_data)
{
	if (!(global_data->arena = (unsigned char*)malloc(sizeof(unsigned char)
								* MEM_SIZE)))
		ft_manage_error(global_data, MALLOC_FAIL, -1, 1);
	ft_bzero((void*)global_data->arena, MEM_SIZE);
	ft_get_valid_champions_count(global_data);
	ft_get_starting_points(global_data);
	ft_create_initial_processes(global_data);
	ft_fill_arena(global_data);
	ft_battlegrounds(global_data);
}
