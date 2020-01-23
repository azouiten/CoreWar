/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_load.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:41:53 by ohachim           #+#    #+#             */
/*   Updated: 2020/01/23 07:19:11 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

static int	ft_extract_argument_ind(t_global *global_data, t_process **process, int byte_distance) // Must be tested.
{
	t_hexa		load_union;
	int		cn;

	cn = IND_SIZE - 1;
	while (cn >= 0)
	{
		load_union.buf[cn] = global_data->arena[(*process)->process_cursor + byte_distance];
		byte_distance++;
		cn--;
	}
	return (load_union.value);
}

static int      ft_extract_argument_dir_long(t_global *global_data, t_process **process, int byte_distance) // Might turn into an independent function.
{
        t_hexa          load_union;
        int             cn;

        cn = DIR_SIZE - 1;
        while (cn >= 0)
        {
                load_union.buf[cn] = global_data->arena[(*process)->process_cursor + byte_distance];
                byte_distance++;
                cn--;
        }
        return (load_union.value);
}

void	ft_execute_load(t_process **process, t_global *global_data)
{
	int	load_arg_value;
	int	reg_value;

	ft_printf("helloww\n");
	if ((*process)->arg[0] == IND_CODE)
	{
		load_arg_value = ft_extract_argument_ind(global_data, process, 2) % IDX_MOD;
		reg_value = global_data->arena[(*process)->process_cursor + 4];
		if (reg_value < 1 || reg_value > REG_NUMBER)
			return ;
		(*process)->registries[reg_value - 1] = ft_get_ind_value(global_data, (*process)->process_cursor + load_arg_value); // Add this function.
		if ((*process)->registries[reg_value - 1])
			(*process)->carry = 0;
		else
			(*process)->carry = 1;
	}
	else if ((*process)->arg[0] == DIR_CODE)
	{
		load_arg_value = ft_extract_argument_dir_long(global_data, process, 2); // 2 instead of one to dodge byte code.
		reg_value = global_data->arena[(*process)->process_cursor + 6]; // 1 for op_code + 1 for byte_code + 4 dir bytes == 6;
		if (reg_value < 1 || reg_value > REG_NUMBER)
			return ;
		(*process)->registries[reg_value - 1] = load_arg_value;
		if (load_arg_value)
			(*process)->carry = 0;
		else
			(*process)->carry = 1;
	}
	ft_printf("I am le load_arg_value %d, and I am le reg_value %d, and I am le carry %d\n", load_arg_value, reg_value, (*process)->carry);
}
