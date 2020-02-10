/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_jump_if_zero.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 03:51:31 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/10 05:30:51 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

void	ft_execute_jump_if_zero(t_process **process, t_global *global_data)
{
	int	dir_value;

	if ((*process)->carry)
	{
		dir_value = ft_extract_argument_dir_short(global_data, process, 1);
		(*process)->process_cursor =
			ft_euclidean_mod(((*process)->process_cursor + (dir_value
				% IDX_MOD)), MEM_SIZE);
	}
}
