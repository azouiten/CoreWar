/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_battlegrounds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 01:34:58 by ohachim           #+#    #+#             */
/*   Updated: 2019/12/31 04:11:17 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

static void	ft_get_op(t_global *global_data)
{
	t_pro
}

static int	ft_enough_processes(t_global *global_data)
{
	t_process *temp_processes;

	temp_process = global_data->processes;
	while (temp_process)
	{
		if (temp_process->alive)
			return (1);
		temp_process = temp_process->next;
	}
	return (0);
}

void	ft_battlegrounds(t_global *global_data)
{
	while (global_data->cycles_to_die && ft_enough_processes(global_data))
	{
		global_data->cycles_since_start = 0;
		while (global_data->cycle_since_start < global_data->cycles_to_die)
		{
		/*
		 * Code execution will happen here.
		 */
			ft_get_op(global_data);
			global_data->cycle_since_start += 1;
		}
		/*
		 * Maybe count lives here, maybe we count lives while executing code.
		 * Kill processes that didn't declare live.
		 * Give new values to variables.
		 */
		if (global_data->number_of_checks >= MAX_CHECKS)
			global_data->cycles_to_die -= CYCLE_DELTA;
		if (global_data->number_lives_declared >= NBR_LIVE)
		{
			global_data->cycles_to_die -= CYCLE_DELTA;
			global_data->number_of_checks = 0;
		}
		global_data->number_lives_declared = 0;
	}
}
