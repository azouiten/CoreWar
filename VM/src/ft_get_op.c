/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 03:57:22 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/01 16:13:08 by ohachim          ###   ########.fr       */
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
		if (!op_tab[current_op_index].t_dir_size)
			return (DIR_SIZE); // This one is varible, check later.
		else
			return (DIR_SIZE / 2);
	}
	return (0);
}

static int	ft_count_dodge_bytes(t_global *global_data, t_process **process)
{
	int	bytes;
	int	position;
	int	arg_num;
	int	fail;

	// A condition for arg_type = 0.
	fail = 0;
	arg_num = 0;
	bytes = 1;
	position = 7;
	while (position > 7 - (2 * op_tab[(*process)->current_op - 1].argc)) // Maybe some macros??
	{
		(*process)->arg[arg_num] = ft_get_bit_value(global_data->arena[((*process)->process_cursor + 1) % MEM_SIZE], 2, position);
		bytes += ft_arg_size((*process)->arg[arg_num], (*process)->current_op - 1);
				// Must check arguments validity.
		if (!ft_check_arg_validity((*process)->arg[arg_num], arg_num, (*process)->current_op - 1)) // Seems good, but must recheck.
			fail = 1; // Init.
		position -= 2;
		arg_num++;
	}
	(*process)->bytes_to_next_op = bytes + 1; // Might remove bytes later, might also remove arg_type as it is given in op_tab.
	if (fail)
		return (1);
	return (0);
}

static void	ft_execute_op(t_global *global_data, t_process **process)
{
	int	arg_type;
	int	fail;

	fail = 0;
	if (op_tab[(*process)->current_op - 1].arguments)
		fail = ft_count_dodge_bytes(global_data, process);
	else
	{
		(*process)->arg[0] = op_tab[(*process)->current_op - 1].tab[0];
		(*process)->bytes_to_next_op = ft_arg_size(op_tab[(*process)->current_op - 1].tab[0], (*process)->current_op - 1) + 1;
	}
	if (!fail)
		ft_execute_hq(process, global_data);
	if (!(*process)->carry || (*process)->current_op != 9 || ((*process)->current_op == 9 && (*process)->carry && fail)) // wut if arguments were invalid?
		(*process)->process_cursor = ((*process)->process_cursor + (*process)->bytes_to_next_op) % MEM_SIZE;
	(*process)->current_op = -1;
}

static void	ft_get_new_op(t_global *global_data, t_process **process)
{
	if (global_data->arena[(*process)->process_cursor] == 0)
	{
		(*process)->current_op = -1;
		(*process)->cycles_till_op = 0;
		(*process)->process_cursor = ((*process)->process_cursor + 1) % MEM_SIZE;
		return ;
	}
	(*process)->current_op = global_data->arena[(*process)->process_cursor]; // Will get the current operation's op_code.
	if ((*process)->current_op > 16 || ((*process)->current_op < 1))
	{
		(*process)->cycles_till_op = 0;
		(*process)->process_cursor = ((*process)->process_cursor + 1) % MEM_SIZE;
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
		if (!temp_process->alive)  // Skip if process is dead.
		{
			temp_process = temp_process->next;
			continue ;
		}
		if (temp_process->cycles_till_op == 0)
			ft_get_new_op(global_data, &temp_process);
		if (temp_process->cycles_till_op > 0)
			temp_process->cycles_till_op -= 1;
		if (temp_process->cycles_till_op == 0 && temp_process->current_op <= 16 && temp_process->current_op >= 1) //Condition to exec operation.
		{
			ft_execute_op(global_data, &temp_process);
			ft_print_arena(global_data, MEM_SIZE, global_data->processes->process_cursor);
		}
		temp_process = temp_process->next;
	}
}

