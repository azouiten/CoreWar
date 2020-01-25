/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_store.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 07:30:06 by ohachim           #+#    #+#             */
/*   Updated: 2020/01/25 03:13:17 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"
void	ft_print_arena(t_global *global_data, int xs)
{
	int cn;

	cn = 0;
	while (cn < xs)
	{
		ft_printf("[%.2x]", global_data->arena[cn]);
		cn++;
	}
	ft_printf("\n");
}
static void	ft_arena_cpy(t_global *global_data, int cpy_to, int to_cpy) // Might make independent.
{
	t_hexa	store_hexa;
	int	cn;

	cn = 3;
	store_hexa.value = to_cpy;
	while (cn >= 0)
	{
		global_data->arena[cpy_to] = store_hexa.buf[cn];
		cpy_to++;
		cn--;
	}
	ft_printf("\n");
}

void	ft_execute_store(t_process **process, t_global *global_data)
{
	int	first_arg_value;
	int	second_arg_value;

	first_arg_value = global_data->arena[(*process)->process_cursor + 2]; // Dodging the byte_code with + 2.
	if (first_arg_value < 1 || first_arg_value > REG_NUMBER)
		return ;
	if ((*process)->arg[1] == REG_CODE)
	{
		second_arg_value = global_data->arena[(*process)->process_cursor + 3];
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

