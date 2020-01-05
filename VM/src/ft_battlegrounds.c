/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_battlegrounds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 01:34:58 by ohachim           #+#    #+#             */
/*   Updated: 2020/01/05 07:14:51 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

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
	ft_printf("ah shit here we go again%d\n", alive);
	return (alive);
}

void	ft_battlegrounds(t_global *global_data)
{
	while (global_data->cycles_to_die > 0 && ft_enough_processes(global_data) >= 1)
	{
		ft_printf("ah shit here we go again\n");
		global_data->cycle_since_start = 0;
		while (global_data->cycle_since_start < global_data->cycles_to_die)
		{
		/*
		 * Code execution will happen here.
		 */
			ft_get_op(global_data);
			/*ft_check_arguments(global_data);
			ft_execute_op(global_data);*/
			global_data->cycle_since_start += 1;
		}
		/*
		 * Maybe count lives here, maybe we count lives while executing code.
		 * Kill processes that didn't declare live.
		 * Give new values to variables.
		 * Remeber player who last declared to be alive.
		 */
		if (global_data->number_of_checks >= MAX_CHECKS)
		{
			global_data->cycles_to_die -= CYCLE_DELTA;
			global_data->number_of_checks = 0;
		}
		if (global_data->number_lives_declared >= NBR_LIVE)
		{
			global_data->cycles_to_die -= CYCLE_DELTA;
			global_data->number_of_checks = 0;
		}
		global_data->number_lives_declared = 0;
		global_data->number_of_checks += 1;
		break ;
	}
	/*
	 * We should keep executing code after cycles_to_die is less than or equal to zero, but this time we do the verification after every cycle.
	 * Or maybe we just stop after cycle_to_die reaches 0.
	 */
}
