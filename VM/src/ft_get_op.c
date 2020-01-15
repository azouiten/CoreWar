/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 03:57:22 by ohachim           #+#    #+#             */
/*   Updated: 2020/01/15 12:34:53 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"
#include <stdio.h> // Remove.
// Fix op_tab name (global variable).
static int	ft_arg_size(int	arg, int current_op_index)
{
	if (arg == IND_CODE)
		return (IND_SIZE);
	if (arg == REG_CODE)
		return (1); // In op.h REG_SIZE is 4.
	if (arg == DIR_CODE)
	{
		if (op_tab[current_op_index].t_dir_size)
			return (DIR_SIZE); // This one is varible, check later.
		else
			return (DIR_SIZE / 2);
	}
	return (-1);
}

static int	ft_count_dodge_bytes(t_global *global_data, t_process **process, int arg_type)
{
	int	bytes;
	int	position;
	int	arg_num;
	int	fail;

	fail = 0;
	arg_num = 0;
	bytes = 0;
	position = 1;
	while (position < op_tab[(*process)->current_op - 1].argc * 2)
	{
		(*process)->arg[arg_num] = ft_get_bit_value(global_data->arena[(*process)->process_cursor + arg_type], 2, position);
		bytes += ft_arg_size((*process)->arg[arg_num], (*process)->current_op - 1);
				// Must check arguments validity.
		if (!ft_check_arg_validity(ft_arg_size((*process)->arg[arg_num], (*process)->current_op - 1), position, (*process)->current_op - 1))
			fail = 1; // Init.
		position += 2;
		arg_num++;
	}
	(*process)->bytes_to_next_op = bytes + arg_type; // Might remove bytes later, might also remove arg_type as it is given in op_tab.
	if (fail)
		return (0);
	return (1);
}

static void	ft_execute_op(t_global *global_data, t_process **process)
{
	int	arg_type;
	
	if (op_tab[(*process)->current_op - 1].arguments)
		arg_type = 1;
	else
		arg_type = 0;
	if (ft_count_dodge_bytes(global_data, process, arg_type))
		/*execute*/
	(*process)->process_cursor += (*process)->bytes_to_next_op;
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
		if (temp_process->cycles_till_op == 0 && temp_process->current_op <= 16 && temp_process->current_op >= 1) //Condition to exec operation.
			ft_execute_op(global_data, &temp_process);
		temp_process = temp_process->next;
	}
}

