/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_long_load.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 10:26:05 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/22 13:59:37 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

static void	ft_long_load_dir(t_process **process,
				t_global *global_data, int load_arg_value, int reg_value)
{
	load_arg_value = ft_extract_argument_dir_long(global_data, process, 2);
	reg_value = global_data->arena[((*process)->process_cursor + 6)
		% MEM_SIZE];
	if (reg_value < 1 || reg_value > REG_NUMBER)
		return ;
	(*process)->registries[reg_value - 1] = load_arg_value;
	if (load_arg_value)
		(*process)->carry = 0;
	else
		(*process)->carry = 1;
}

static void	ft_long_load_ind(t_process **process,
				t_global *global_data, int load_arg_value, int reg_value)
{
	load_arg_value = ft_extract_argument_ind(global_data, process, 2);
	reg_value =
		global_data->arena[ft_euclidean_mod(((*process)->process_cursor
			+ 4), MEM_SIZE)];
	if (reg_value < 1 || reg_value > REG_NUMBER)
		return ;
	(*process)->registries[reg_value - 1] =
		ft_get_ind_value(global_data,
			ft_euclidean_mod(((*process)->process_cursor + load_arg_value),
				MEM_SIZE));
	if ((*process)->registries[reg_value - 1])
		(*process)->carry = 0;
	else
		(*process)->carry = 1;
}

void		ft_execute_long_load(t_process **process, t_global *global_data)
{
	int		load_arg_value;
	int		reg_value;

	load_arg_value = 0;
	reg_value = 0;
	if ((*process)->arg[0] == IND_CODE)
		ft_long_load_ind(process, global_data, load_arg_value, reg_value);
	else if ((*process)->arg[0] == DIR_CODE)
		ft_long_load_dir(process, global_data, load_arg_value, reg_value);
}
