/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_xor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 02:43:20 by ohachim           #+#    #+#             */
/*   Updated: 2020/01/30 18:25:14 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

void	ft_execute_xor(t_process **process, t_global *global_data)
{
	int	first_arg;
	int	second_arg;
	int	reg;
	int	dodge;

	dodge = 2;
	first_arg = ft_get_arg(process, global_data, &dodge, 0);
	// ft_printf("first_arg is %d, in hexa %#x\n", first_arg, first_arg);
	second_arg = ft_get_arg(process, global_data, &dodge, 1);
	// ft_printf("second in arg is %d, in hexa\n", second_arg, second_arg);
	reg = global_data->arena[((*process)->process_cursor + dodge) % MEM_SIZE];
	// ft_printf("reg is %d\n", reg);
	(*process)->registries[reg - 1] = first_arg ^ second_arg;
	// ft_printf("thei ^ is %d, in hexa %#x\n", (*process)->registries[reg - 1]);
	if ((*process)->registries[reg - 1])
		(*process)->carry = 0;
	else
		(*process)->carry = 1;
}
