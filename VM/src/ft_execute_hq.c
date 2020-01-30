/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_hq.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:59:03 by ohachim           #+#    #+#             */
/*   Updated: 2020/01/30 19:19:30 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

void	ft_execute_hq(t_process **process, t_global *global_data)
{
	ft_printf("process_cursor == %d\n", (*process)->process_cursor);
	if ((*process)->current_op == LIVE)
		ft_execute_live(process, global_data);
	else if ((*process)->current_op == LOAD && ft_printf("load\n"))
		ft_execute_load(process, global_data);
	else if ((*process)->current_op == STORE && ft_printf("store\n"))
		ft_execute_store(process, global_data);
	else if ((*process)->current_op == ADDITION && ft_printf("addition\n"))
		ft_execute_addition(process, global_data);
	else if ((*process)->current_op == SUBSTRACTION && ft_printf("substraction\n"))
		ft_execute_substraction(process, global_data);
	else if ((*process)->current_op == OR && ft_printf("or\n"))
		ft_execute_or(process, global_data);
	else if ((*process)->current_op == XOR && ft_printf("xor\n"))
		ft_execute_xor(process, global_data);
	else if ((*process)->current_op == AND && ft_printf("and\n"))
		ft_execute_and(process, global_data);
	else if ((*process)->current_op == JUMP_IF_ZERO && ft_printf("jump if zero\n"))
		ft_execute_jump_if_zero(process, global_data);
	else if ((*process)->current_op == LOAD_INDEX && ft_printf("load_index\n"))
		ft_execute_load_index(process, global_data);
	else if ((*process)->current_op == STORE_INDEX && ft_printf("store\n"))
		ft_execute_store_index(process, global_data);
	else if ((*process)->current_op == FORK && ft_printf("fork\n"))
		ft_execute_fork(process, global_data);
	else if ((*process)->current_op == LONG_FORK && ft_printf("long_fork\n"))
		ft_execute_long_fork(process, global_data);
	else if ((*process)->current_op == LONG_LOAD && ft_printf("long_load\n"))
		ft_execute_long_load(process, global_data);
	else if ((*process)->current_op == LONG_LOAD_INDEX && ft_printf("long_load_index\n"))
		ft_execute_long_load_index(process, global_data);
	else if ((*process)->current_op == AFF && ft_printf("aff\n"))
		ft_execute_aff(process, global_data);
	ft_printf("at: %d===\n", global_data->all_time_cycles);
	ft_print_arena(global_data, MEM_SIZE, global_data->processes->process_cursor);
}
