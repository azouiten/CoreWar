/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_hq.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:59:03 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/01 16:52:35 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h" // 3275

void	ft_execute_hq(t_process **process, t_global *global_data)
{
	if (DEBUG)
		ft_printf("process_cursor == %d\n", (*process)->process_cursor);
	if ((*process)->current_op == LIVE)
	{
		if (DEBUG)
			ft_printf("live\n");
		ft_execute_live(process, global_data);
	}
	else if ((*process)->current_op == LOAD)
	{
		if (DEBUG)
			ft_printf("load\n");
		ft_execute_load(process, global_data);
	}
	else if ((*process)->current_op == STORE)
	{
		if (DEBUG)
			ft_printf("store\n");
		ft_execute_store(process, global_data);
	}
	else if ((*process)->current_op == ADDITION)
	{
		if (DEBUG)
			ft_printf("additio\n");
		ft_execute_addition(process, global_data);
	}
	else if ((*process)->current_op == SUBSTRACTION)
	{
		if (DEBUG)
			ft_printf("substration\n");
		ft_execute_substraction(process, global_data);
	}
	else if ((*process)->current_op == OR)
	{
		if (DEBUG)
			ft_printf("or\n");
		ft_execute_or(process, global_data);
	}
	else if ((*process)->current_op == XOR )
	{
		if (DEBUG)
			ft_printf("xor\n");
		ft_execute_xor(process, global_data);
	}
	else if ((*process)->current_op == AND)
	{
		if (DEBUG)
			ft_printf("and\n");
		ft_execute_and(process, global_data);
	}
	else if ((*process)->current_op == JUMP_IF_ZERO)
	{
		if (DEBUG)
			ft_printf("jump if zero\n");
		ft_execute_jump_if_zero(process, global_data);
	}
	else if ((*process)->current_op == LOAD_INDEX )
	{
		if (DEBUG)
			ft_printf("load_indx\n");
		ft_execute_load_index(process, global_data);
	}
	else if ((*process)->current_op == STORE_INDEX)
	{
		if (DEBUG)
			ft_printf("store\n");
		ft_execute_store_index(process, global_data);
	}
	else if ((*process)->current_op == FORK)
	{
		if (DEBUG)
			ft_printf("fork\n");
		ft_execute_fork(process, global_data);
	}
	else if ((*process)->current_op == LONG_FORK)
	{
		if (DEBUG)
			ft_printf("long_fok\n");
		ft_execute_long_fork(process, global_data);
	}
	else if ((*process)->current_op == LONG_LOAD)
	{
		if (DEBUG)
			ft_printf("long_load\n");
		ft_execute_long_load(process, global_data);
	}
	else if ((*process)->current_op == LONG_LOAD_INDEX)
	{
		if (DEBUG)
			ft_printf("long_lod_index\n");
		ft_execute_long_load_index(process, global_data);
	}
	else if ((*process)->current_op == AFF)
	{
		if (DEBUG)
			ft_printf("aff\n");
		ft_execute_aff(process, global_data);
	}
	ft_printf("%d\n", global_data->all_time_cycles + 1);
}
