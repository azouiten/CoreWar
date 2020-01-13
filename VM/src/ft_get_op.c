/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 03:57:22 by ohachim           #+#    #+#             */
/*   Updated: 2020/01/13 12:30:16 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"
#include <stdio.h>

static int	ft_arg_size(int	arg)
{
	if (arg == IND_CODE)
		return (IND_SIZE);
	if (arg == REG_CODE)
		return (1); // In op.h REG_SIZE is 4.
	if (arg == DIR_CODE)
		return (DIR_SIZE); // This one is varible, check later.
	return (-1);
}

static int	ft_count_dodge_bytes(t_global *global_data, t_process **process, int arg_type)
{
	int	bytes;
	int	position;
	int	arg_num;

	arg_num = 0;
	bytes = 1;
	position = 1;
	while (position < op_tab[(*process)->current_op - 1].argc * 2)
	{
		(*process)->arg[arg_num] = ft_get_bit_value(global_data->arena[(*process)->processd_cursor + arg_type], 2, position);
		bytes += ft_arg_size((*process)->arg[arg_num];
		position += 2;
		arg_num++;
	}
	(*process)->bytes_to_next_op = bytes + arg_type; // Might remove bytes later, might also remove arg_type as it is given in op_tab.
}

static void	ft_execute_op(t_global *global_data, t_process **process)
{
	int	arg_type;
	
	if (op_tap[(*process)->current_op - 1].arguments)
		arg_type = 1;
	else
		arg_type = 0;
	ft_count_dodge_bytes(global_data, process, arg_type);
/*	if (arg are not valid)
		(*process)->process_cursor += (*process)->bytes_to_next_op;
	else
	execute*/
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

