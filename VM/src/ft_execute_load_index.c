/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_load_index.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 09:05:50 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/10 05:33:15 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

void	ft_execute_load_index(t_process **process, t_global *global_data)
{
	int	first_arg;
	int	second_arg;
	int	reg;
	int	dodge;
	int	adress_value;

	dodge = 2;
	first_arg = ft_get_arg_short(process, global_data, &dodge, 0);
	second_arg = ft_get_arg_short(process, global_data, &dodge, 1);
	reg = global_data->arena[((*process)->process_cursor + dodge) % MEM_SIZE];
	if (reg < 1 || reg > REG_NUMBER)
		return ;
	adress_value = ft_get_ind_value(global_data,
		(ft_euclidean_mod((*process)->process_cursor
			+ ((first_arg + second_arg) % IDX_MOD), MEM_SIZE)));
	(*process)->registries[reg - 1] = adress_value;
}
