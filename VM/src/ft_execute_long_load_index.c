/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_long_load_index.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 09:05:50 by ohachim           #+#    #+#             */
/*   Updated: 2020/01/25 10:35:35 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

void	ft_execute_long_load_index(t_process **process, t_global *global_data)
{
	int	first_arg;
	int	second_arg;
	int	reg;
	int	dodge;
	int	adress_value;

	dodge = 2;
	first_arg = ft_get_arg_short(process, global_data, &dodge, 0);
	second_arg = ft_get_arg_short(process, global_data, &dodge, 1);
	reg = global_data->arena[(*process)->process_cursor + dodge];
	if (reg < 1 || reg > REG_NUMBER)
		return ;
	adress_value = ft_get_ind_value(global_data, ((*process)->process_cursor + first_arg + second_arg)); // Check if this is how we idx_mode.
	(*process)->registries[reg - 1] = adress_value;
}
