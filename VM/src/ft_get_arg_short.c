/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_short.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 09:41:58 by ohachim           #+#    #+#             */
/*   Updated: 2020/01/30 10:03:10 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

int     ft_get_arg_short(t_process **process, t_global *global_data, int *dodge, int arg_index) // Only works if dir is 2 bytes.
{
	int     arg;

	if ((*process)->arg[arg_index] == REG_CODE)
	{
		arg = global_data->arena[((*process)->process_cursor + *dodge) % MEM_SIZE];
		arg = (*process)->registries[arg - 1];
		*dodge = *dodge + 1;
	}
	else if ((*process)->arg[arg_index] == IND_CODE)
	{
		arg = ft_extract_argument_ind(global_data, process, *dodge) % IDX_MOD;
		arg = ft_get_ind_value(global_data, ft_euclidean_mod(arg + (*process)->process_cursor, MEM_SIZE));
		*dodge = *dodge + 2;
	}
	else if ((*process)->arg[arg_index] == DIR_CODE)
	{
		arg = ft_extract_argument_dir_short(global_data, process, *dodge);
		*dodge = *dodge + 2;
	}
	return (arg);
}
