/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 03:57:22 by ohachim           #+#    #+#             */
/*   Updated: 2020/01/12 00:34:42 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"
#include <stdio.h>

static int	ft_count_dodge_bits(t_global *global_data, t_process **process)
{
	
}	

static void	ft_execute_op(t_global *global_data, t_process **process)
{
	int	arg_type;

	arg_type = global_data->arena[(*process)->process_cursor + 1];
}

static void	ft_get_new_op(t_global *global_data, t_process **process)
{
	(*process)->current_op = global_data->arena[(*process)->process_cursor]; // Will get the current operation's op_code.
	if ((*process)->current_op > 16 || ((*process)->current_op < 0))
	{
		(*process)->cycles_till_op = 0;
		(*process)->process_cursor = (*process)->process_cursor + 1;
	}
	else
		(*process)->cycles_till_op = op_tab[(*process)->current_op - 1].cost; // Get the current operation's cost/number of cycles.
}

void	ft_get_op(t_global *global_data)
{
	t_process	*temp_process;
	
	temp_process = global_data->processes;
	while (temp_process)
	{
		printf("hello\n");
		if (temp_process->cycles_till_op == 0)
			ft_get_new_op(global_data, &temp_process);
		if (temp_process->cycles_till_op > 0)
			temp_process->cycles_till_op -= 1;
//		if (temp_process->cycles_till_op == 0 && temp_process->current_op <= 16 && temp_process->current_op >= 1) Condition to exec operation.
//			ft_execute_op
		temp_process = temp_process->next;
	}
}

