/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 03:37:34 by ohachim           #+#    #+#             */
/*   Updated: 2020/01/25 03:44:09 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

int     ft_get_arg(t_process **process, t_global *global_data, int *dodge, int arg_index)
{
	int     arg;

	if ((*process)->arg[arg_index] == REG_CODE)
	{
		arg = global_data->arena[(*process)->process_cursor + *dodge];
		arg = (*process)->registries[arg - 1];
		*dodge = *dodge + 1;
	}
	else if ((*process)->arg[arg_index] == IND_CODE)
	{
		arg = ft_extract_argument_ind(global_data, process, *dodge) % IDX_MOD;
		arg = ft_get_ind_value(global_data, arg + (*process)->process_cursor);
		*dodge = *dodge + 2;
	}
	else if ((*process)->arg[arg_index] == DIR_CODE)
	{
		arg = ft_extract_argument_dir_long(global_data, process, *dodge);
		*dodge = *dodge + 4;
	}
	return (arg);
}
