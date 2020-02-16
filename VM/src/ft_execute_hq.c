/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_hq.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:59:03 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/16 19:53:54 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

static void	ft_arena_neutral_ops(t_process **process, t_global *global_data)
{
	if ((*process)->current_op == LIVE)
		ft_execute_live(process, global_data);
	else if ((*process)->current_op == AFF)
		ft_execute_aff(process, global_data);
}

static void	ft_arena_mutilator_ops(t_process **process, t_global *global_data)
{
	if ((*process)->current_op == LOAD)
		ft_execute_load(process, global_data);
	else if ((*process)->current_op == LOAD_INDEX)
		ft_execute_load_index(process, global_data);
	else if ((*process)->current_op == LONG_LOAD)
		ft_execute_long_load(process, global_data);
	else if ((*process)->current_op == LONG_LOAD_INDEX)
		ft_execute_long_load_index(process, global_data);
	else if ((*process)->current_op == STORE)
		ft_execute_store(process, global_data);
	else if ((*process)->current_op == STORE_INDEX)
		ft_execute_store_index(process, global_data);
}

static void	ft_process_navigation(t_process **process, t_global *global_data)
{
	if ((*process)->current_op == FORK)
		ft_execute_fork(process, global_data);
	else if ((*process)->current_op == LONG_FORK)
		ft_execute_long_fork(process, global_data);
	else if ((*process)->current_op == JUMP_IF_ZERO)
		ft_execute_jump_if_zero(process, global_data);
}

static void	ft_bit_operations(t_process **process, t_global *global_data)
{
	if ((*process)->current_op == ADDITION)
		ft_execute_addition(process, global_data);
	else if ((*process)->current_op == SUBSTRACTION)
		ft_execute_substraction(process, global_data);
	else if ((*process)->current_op == OR)
		ft_execute_or(process, global_data);
	else if ((*process)->current_op == XOR)
		ft_execute_xor(process, global_data);
	else if ((*process)->current_op == AND)
		ft_execute_and(process, global_data);
}

void		ft_execute_hq(t_process **process, t_global *global_data)
{
	ft_arena_neutral_ops(process, global_data);
	ft_arena_mutilator_ops(process, global_data);
	ft_process_navigation(process, global_data);
	ft_bit_operations(process, global_data);
}
