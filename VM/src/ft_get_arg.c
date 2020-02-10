/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 03:37:34 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/10 06:05:18 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

int		ft_get_arg(t_process **process, t_global *global_data,
			int *dodge, int arg_index)
{
	int	arg;

	if ((*process)->arg[arg_index] == REG_CODE)
	{
		arg = global_data->arena[((*process)->process_cursor + *dodge)
			% MEM_SIZE];
		if (arg < 1 || arg > REG_NUMBER)
			return (-1);
		arg = (*process)->registries[arg - 1];
		*dodge = *dodge + 1;
	}
	else if ((*process)->arg[arg_index] == IND_CODE)
	{
		arg = ft_extract_argument_ind(global_data, process, *dodge);
		arg = ft_get_ind_value(global_data,
			ft_euclidean_mod(((*process)->process_cursor + (arg % IDX_MOD)),
				MEM_SIZE));
		*dodge = *dodge + 2;
	}
	else if ((*process)->arg[arg_index] == DIR_CODE)
	{
		arg = ft_extract_argument_dir_long(global_data, process, *dodge);
		*dodge = *dodge + 4;
	}
	return (arg);
}
