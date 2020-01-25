/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_jump_if_zero.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 03:51:31 by ohachim           #+#    #+#             */
/*   Updated: 2020/01/25 04:05:29 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

void	ft_execute_jump_if_zero(t_process **process, t_global *global_data)
{
	int	dir_value;

	dir_value = ft_extract_argument_dir_short(global_data, process, 1);
	if ((*process)->carry)
		(*process)->process_cursor = (*process)->process_cursor + (dir_value % IDX_MOD);
}
