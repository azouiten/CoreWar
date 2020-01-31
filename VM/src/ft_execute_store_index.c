/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_store_index.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 09:24:56 by ohachim           #+#    #+#             */
/*   Updated: 2020/01/31 14:49:05 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

void	ft_execute_store_index(t_process **process, t_global *global_data)
{
	int	reg;
	int	dodge;
	int	second_arg;
	int	third_arg;

	reg = global_data->arena[((*process)->process_cursor + 2) % MEM_SIZE];
	if (DEBUG)
		ft_printf("reg is %d\n", reg);
	if (reg < 1 || reg > REG_NUMBER)
		return ;
	dodge = 3;
	second_arg = ft_get_arg_short(process, global_data, &dodge, 1);
	if (DEBUG)
		ft_printf("second_arg if %d, in hexa %#x\n", second_arg, second_arg);
	third_arg = ft_get_arg_short(process, global_data, &dodge, 2);
	if (DEBUG)
		ft_printf("third_arg is %d, in hexa %#x\n", third_arg, third_arg);
	ft_arena_cpy(global_data, (*process)->process_cursor + ((second_arg + third_arg) % IDX_MOD), (*process)->registries[reg - 1]);
}
