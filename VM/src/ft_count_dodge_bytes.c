/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_dodge_bytes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 23:50:22 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/14 19:03:13 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

int			ft_count_dodge_bytes(t_global *global_data,
					t_process **process, int fail, int arg_num)
{
	int				bytes;
	int				position;

	bytes = 1;
	position = 7;
	while (position > 7 - (2 * g_op_tab[(*process)->current_op - 1].argc))
	{
		(*process)->arg[arg_num] =
		ft_get_bit_value(global_data->arena[((*process)->process_cursor + 1)
		% MEM_SIZE], 2, position);
		if (!ft_check_registries(process, bytes + 1, arg_num, global_data))
			fail = 1;
		bytes += ft_arg_size((*process)->arg[arg_num], (*process)->current_op
					- 1);
		if (!ft_check_arg_validity((*process)->arg[arg_num], arg_num,
			(*process)->current_op - 1))
			fail = 1;
		position -= 2;
		arg_num++;
	}
	(*process)->bytes_to_next_op = bytes + 1;
	if (fail)
		return (1);
	return (0);
}
