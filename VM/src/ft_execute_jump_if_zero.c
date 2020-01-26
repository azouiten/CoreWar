/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_jump_if_zero.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 03:51:31 by ohachim           #+#    #+#             */
/*   Updated: 2020/01/26 12:41:25 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

void	ft_execute_jump_if_zero(t_process **process, t_global *global_data)
{
	int	dir_value;

	if ((*process)->carry)
	{
		dir_value = ft_extract_argument_dir_short(global_data, process, 1);
		(*process)->process_cursor = ((*process)->process_cursor + (dir_value % IDX_MOD)) % MEM_SIZE;
		ft_printf("jump == %d, (cursor) %d\n", dir_value, (*process)->process_cursor);
	}
}
