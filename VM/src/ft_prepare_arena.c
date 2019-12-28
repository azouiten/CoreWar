/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_arena.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 14:23:25 by ohachim           #+#    #+#             */
/*   Updated: 2019/12/28 15:12:53 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

static void	ft_create_processes(t_global *global_data)
{
	int		i;
	int		j;

	i = 0;
	if (!(global_data->processes = malloc(sizeof(t_process) * global_data->valid_champions)))  // TODO Free this.
		ft_manage_error(global_data, MALLOC_FAIL, -1, 1);
	while (i < global_data->valid_champions)
	{
		global_data->processes[i].carry = 0;
		global_data->processes[i].last_live = -1;
		global_data->processes[i].cycles_till_op = -1;
		global_data->processes[i].bytes_to_next_op = -1;
		if (!(global_data->processes[i].registries = malloc(sizeof(t_reg) * REG_SIZE)))  // TODO Free this.
			ft_manage_error(global_data, MALLOC_FAIL, -1, 1);
		j = 1;
		while (j < REG_SIZE)
		{
			global_data->processes[i].registries[j].value = 0;
			j++;
		}
		i++;
	}
}

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
		global_data->processes[checked].program_counter.value = mem_point;
		global_data->processes[checked].registries[0].value = checked * -1; // TODO check if this value needs to be negative.
		mem_point = mem_point + step;
		checked++;
	}
	global_data->champions[checked - 1] = global_data->champions[i];
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
	if (!(global_data->arena = (unsigned char*)malloc(sizeof(unsigned char) * MEM_SIZE))) // TODO Free this.
		ft_manage_error(global_data, MALLOC_FAIL, -1, 1);
	ft_bzero((void*)global_data->arena, MEM_SIZE);
	ft_get_valid_champions_count(global_data);
	ft_create_processes(global_data);
	ft_get_starting_points(global_data);
	ft_fill_arena(global_data);
}
