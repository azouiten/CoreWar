/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_battlegrounds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melalj <melalj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 01:34:58 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/26 03:41:28 by melalj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

static int		ft_cremate_dead_processes(t_global *global_data)
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
		temp_process->arg[0] = 0;
		temp_process->arg[1] = 0;
		temp_process->arg[2] = 0;
		temp_process = temp_process->next;
	}
	return (0);
}

static int		ft_enough_processes(t_global *global_data)
{
	t_process	*temp_process;
	int			alive;

	alive = 0;
	temp_process = global_data->processes;
	while (temp_process)
	{
		if (temp_process->alive)
			alive++;
		temp_process = temp_process->next;
	}
	global_data->cycle_since_start = 0;
	return (alive);
}

static void		ft_verification(t_global *global_data)
{
	if (global_data->number_lives_declared >= NBR_LIVE)
	{
		global_data->cycles_to_die -= CYCLE_DELTA;
		global_data->number_of_checks = 0;
		global_data->number_lives_declared = 0;
		return ;
	}
	else
		global_data->number_of_checks += 1;
	if (global_data->number_of_checks >= MAX_CHECKS)
	{
		global_data->cycles_to_die -= CYCLE_DELTA;
		global_data->number_of_checks = 0;
	}
	global_data->number_lives_declared = 0;
}

static void		ft_battlegrounds_afterlife(t_global *global_data, t_visu screen)
{
	if (global_data->all_time_cycles
		> global_data->dump_cycle && global_data->print == 1)
		ft_print_arena(global_data, MEM_SIZE);
	while (ft_enough_processes(global_data))
	{
		while (global_data->cycle_since_start < 1)
		{
			visu_key_handling(global_data, screen);
			ft_get_op(global_data, NULL);
			global_data->cycle_since_start += 1;
		}
		ft_cremate_dead_processes(global_data);
		if (!ft_enough_processes(global_data))
			break ;
		ft_verification(global_data);
	}
}

void			ft_battlegrounds(t_global *global_data, int after_life,
					t_visu screen)
{
	while (global_data->cycles_to_die > 0
			&& ft_enough_processes(global_data) >= 1)
	{
		while (global_data->cycle_since_start < global_data->cycles_to_die)
		{
			visu_key_handling(global_data, screen);
			ft_get_op(global_data, NULL);
			global_data->cycle_since_start += 1;
		}
		ft_cremate_dead_processes(global_data);
		if (global_data->all_time_cycles > global_data->dump_cycle
				&& global_data->print == 1)
			ft_print_arena(global_data, MEM_SIZE);
		if (!ft_enough_processes(global_data) && !(after_life = 0))
			break ;
		ft_verification(global_data);
	}
	if (after_life && ++global_data->all_time_cycles)
		ft_battlegrounds_afterlife(global_data, screen);
	visu_key_handling(global_data, screen);
	end_visu(global_data);
}
