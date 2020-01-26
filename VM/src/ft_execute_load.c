/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_load.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:41:53 by ohachim           #+#    #+#             */
/*   Updated: 2020/01/26 13:34:23 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

void	ft_execute_load(t_process **process, t_global *global_data)
{
	int	load_arg_value;
	int	reg_value;

	if ((*process)->arg[0] == IND_CODE)
	{
		load_arg_value = ft_extract_argument_ind(global_data, process, 2);
		reg_value = global_data->arena[((*process)->process_cursor + 4) % MEM_SIZE];
		if (reg_value < 1 || reg_value > REG_NUMBER)
			return ;
		(*process)->registries[reg_value - 1] = ft_get_ind_value(global_data, ((*process)->process_cursor + (load_arg_value % IDX_MOD) % MEM_SIZE));
		if ((*process)->registries[reg_value - 1])
			(*process)->carry = 0;
		else
			(*process)->carry = 1;
	}
	else if ((*process)->arg[0] == DIR_CODE)
	{
		load_arg_value = ft_extract_argument_dir_long(global_data, process, 2); // 2 instead of one to dodge byte code.
		reg_value = global_data->arena[((*process)->process_cursor + 6) % MEM_SIZE]; // 1 for op_code + 1 for byte_code + 4 dir bytes == 6;
		if (reg_value < 1 || reg_value > REG_NUMBER)
			return ;
		(*process)->registries[reg_value - 1] = load_arg_value;
		if (load_arg_value)
			(*process)->carry = 0;
		else
			(*process)->carry = 1;
	}
}
