/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_hq.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:59:03 by ohachim           #+#    #+#             */
/*   Updated: 2020/01/30 10:31:20 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

void	ft_execute_hq(t_process **process, t_global *global_data)
{
	ft_printf("\n");
	if ((*process)->current_op == LIVE && ft_printf("We in it to live it\n"))
		ft_execute_live(process, global_data);
	else if ((*process)->current_op == LOAD && ft_printf("We in it to load it\n"))
		ft_execute_load(process, global_data);
	else if ((*process)->current_op == STORE && ft_printf("We in it to store it\n"))
		ft_execute_store(process, global_data);
	else if ((*process)->current_op == ADDITION && ft_printf("We in it to add it\n"))
		ft_execute_addition(process, global_data);
	else if ((*process)->current_op == SUBSTRACTION && ft_printf("We in it to substract it\n"))
		ft_execute_substraction(process, global_data);
	else if ((*process)->current_op == OR && ft_printf("We in it to or it\n"))
		ft_execute_or(process, global_data);
	else if ((*process)->current_op == XOR && ft_printf("We in it to xor it\n"))
		ft_execute_xor(process, global_data);
	else if ((*process)->current_op == AND && ft_printf("We in it and it\n"))
		ft_execute_and(process, global_data);
	else if ((*process)->current_op == JUMP_IF_ZERO && ft_printf("We in it to jump it\n"))
		ft_execute_jump_if_zero(process, global_data);
	else if ((*process)->current_op == LOAD_INDEX && ft_printf("We in it to load_index it\n"))
		ft_execute_load_index(process, global_data);
	else if ((*process)->current_op == STORE_INDEX && ft_printf("We in it to store_index it\n"))
		ft_execute_store_index(process, global_data);
	else if ((*process)->current_op == FORK && ft_printf("We in it to fork it\n"))
		ft_execute_fork(process, global_data);
	else if ((*process)->current_op == LONG_FORK && ft_printf("We in it to long_fork it\n"))
		ft_execute_long_fork(process, global_data);
	else if ((*process)->current_op == LONG_LOAD && ft_printf("We in it to long_load it\n"))
		ft_execute_long_load(process, global_data);
	else if ((*process)->current_op == LONG_LOAD_INDEX && ft_printf("We in it to long_load_index it\n"))
		ft_execute_long_load_index(process, global_data);
	else if ((*process)->current_op == AFF && ft_printf("We in it to aff it\n"))
		ft_execute_aff(process, global_data);
}
