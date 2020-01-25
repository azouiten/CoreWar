/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_hq.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:59:03 by ohachim           #+#    #+#             */
/*   Updated: 2020/01/25 03:54:01 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

void	ft_execute_hq(t_process **process, t_global *global_data)
{
	if ((*process)->current_op == LIVE)
		ft_execute_live(process, global_data);
	else if ((*process)->current_op == LOAD)
		ft_execute_load(process, global_data);
	else if ((*process)->current_op == STORE)
		ft_execute_store(process, global_data);
	else if ((*process)->current_op == ADDITION)
		ft_execute_addition(process, global_data);
	else if ((*process)->current_op == SUBSTRACTION)
		ft_execute_substraction(process, global_data);
	else if ((*process)->current_op == OR)
		ft_execute_or(process, global_data);
	else if ((*process)->current_op == XOR)
		ft_execute_xor(process, global_data);
	else if ((*process)->current_op == AND)
		ft_execute_and(process, global_data);
	else if ((*process)->current_op == JUMP_IF_ZERO)
		ft_execute_jump_if_zero(process, global_data);
}
