/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_store.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 07:30:06 by ohachim           #+#    #+#             */
/*   Updated: 2020/01/29 13:08:37 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

void	ft_execute_store(t_process **process, t_global *global_data)
{
	int	first_arg_value;
	int	second_arg_value;

	first_arg_value = global_data->arena[((*process)->process_cursor + 2) % MEM_SIZE]; // Dodging the byte_code with + 2.
	if (first_arg_value < 1 || first_arg_value > REG_NUMBER)
		return ;
	if ((*process)->arg[1] == REG_CODE)
	{
		second_arg_value = global_data->arena[((*process)->process_cursor + 3) % MEM_SIZE];
		if (second_arg_value > 1 || second_arg_value > REG_NUMBER)
			return ;
		(*process)->registries[second_arg_value - 1] = (*process)->registries[first_arg_value - 1];
	}
	if ((*process)->arg[1] == IND_CODE)
	{
		second_arg_value = ft_extract_argument_ind(global_data, process, 3) % IDX_MOD;
		ft_arena_cpy(global_data, second_arg_value + (*process)->process_cursor, (*process)->registries[first_arg_value - 1]);
	}
}

