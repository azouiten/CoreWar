/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 03:57:22 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/02 18:38:17 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"
#include <stdio.h> // Remove.
// Fix op_tab name (global variable).
int		ft_count_processes(t_global *global_data);
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

static int	ft_check_registries(t_process **process, int reg_index, int arg_num, t_global *global_data)
{
	int		reg;

	reg = 0;
	if ((*process)->arg[arg_num] != REG_CODE)
		return (1);
	reg = global_data->arena[((*process)->process_cursor + reg_index) % MEM_SIZE];
	if (reg < 1 || reg > REG_NUMBER)
		return (0);
	return (1);
}

static int	ft_count_dodge_bytes(t_global *global_data, t_process **process)
{
	int	bytes;
	int	position;
	int	arg_num;
	int	fail;

	fail = 0;
	arg_num = 0;
	bytes = 1;
	position = 7;
	while (position > 7 - (2 * op_tab[(*process)->current_op - 1].argc)) // Maybe some macros??
	{
		(*process)->arg[arg_num] = ft_get_bit_value(global_data->arena[((*process)->process_cursor + 1) % MEM_SIZE], 2, position);
		if (!ft_check_registries(process, bytes + 1, arg_num, global_data))
			fail = 1;
		bytes += ft_arg_size((*process)->arg[arg_num], (*process)->current_op - 1);
				// Must check arguments validity.
		if (!ft_check_arg_validity((*process)->arg[arg_num], arg_num, (*process)->current_op - 1)) // Seems good, but must recheck. // Check for registrie invalidity here.
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
	(*process)->cycles_till_op = 0; // Should remove.
}

static void	ft_get_new_op(t_global *global_data, t_process **process)
{
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
			ft_execute_op(global_data, &temp_process);
		temp_process = temp_process->next;
	}
	if (DEBUG || global_data->all_time_cycles == 8988)
		ft_printf("at cylce %d\n", global_data->all_time_cycles);
	if (DEBUG || global_data->all_time_cycles == 8988)
	{
		ft_print_arena(global_data, MEM_SIZE, global_data->processes->process_cursor);
		ft_printf("number of processes alive is %d\n", ft_count_processes(global_data));
		ft_printf("\n");
	}
}

