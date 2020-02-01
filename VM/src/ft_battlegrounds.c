/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_battlegrounds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 01:34:58 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/01 23:12:33 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"
static int	ft_cremate_dead_processes(t_global *global_data)
{
	t_process	*temp_process;

	temp_process = global_data->processes;
	while (temp_process)
	{
		if (!temp_process->alive)
		{
			temp_process = temp_process->next;
			continue ;
		}
		if (!temp_process->live_declared)
			temp_process->alive = 0;
		temp_process->live_declared = 0;
		temp_process->last_live_cycle = 0; // Might be uselss, Will change to one that keeps an all_time counter.
		temp_process->arg[0] = 0;
		temp_process->arg[1] = 0;
		temp_process->arg[2] = 0;
		temp_process = temp_process->next;
	}
	return (0);
}

static int	ft_enough_processes(t_global *global_data)
{
	t_process *temp_process;
	int		alive;

	alive = 0;
	temp_process = global_data->processes;
	while (temp_process)
	{
		if (temp_process->alive)
			alive++;
		temp_process = temp_process->next;
	}
	return (alive);
}
// Remeber to check if player size is too big by reading one extra byte, or not....
void	ft_battlegrounds(t_global *global_data)
{
	ft_print_arena(global_data, MEM_SIZE, global_data->processes->process_cursor);
	while (global_data->cycles_to_die > 0 && ft_enough_processes(global_data) >= 1)
	{
		global_data->cycle_since_start = 0; // Add variables for live.
		while (global_data->cycle_since_start < global_data->cycles_to_die) // global_data->cycles_to_die
		{
			ft_get_op(global_data);
			global_data->all_time_cycles += 1;
			global_data->cycle_since_start += 1;
		}
		ft_cremate_dead_processes(global_data);
		if (global_data->number_lives_declared >= NBR_LIVE)
		{
			global_data->cycles_to_die -= CYCLE_DELTA;
			global_data->number_of_checks = 0;
			global_data->number_lives_declared = 0;
			continue ;
		}
		else
			global_data->number_of_checks += 1;
		if (global_data->number_of_checks >= MAX_CHECKS)
		{
			global_data->cycles_to_die -= CYCLE_DELTA;
			global_data->number_of_checks = 0;
		}
	}
	ft_printf("%d\n", global_data->all_time_cycles);
	ft_print_arena(global_data, MEM_SIZE, global_data->processes->process_cursor);
}
