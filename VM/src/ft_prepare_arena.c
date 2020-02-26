/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_arena.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melalj <melalj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 14:23:25 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/26 03:45:32 by melalj           ###   ########.fr       */
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
		global_data->champions[i].number = checked;
		checked++;
	}
	global_data->last_live_player = global_data->champions[i];
}

void		ft_prepare_arena(t_global *global_data)
{
	t_visu	screen;

	if (!(global_data->arena = (unsigned char*)malloc(sizeof(unsigned char)
								* MEM_SIZE)))
		ft_manage_error(global_data, MALLOC_FAIL, -1, 1);
	ft_bzero((void*)global_data->arena, MEM_SIZE);
	ft_get_starting_points(global_data);
	ft_create_initial_processes(global_data);
	ft_fill_arena(global_data);
	screen.win_arena = NULL;
	screen.win_stats = NULL;
	if (global_data->v)
		screen = visu_battlegrounds(global_data);
	ft_battlegrounds(global_data, 1, screen);
}
