/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_long_fork.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 10:14:11 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/22 13:59:03 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

void	ft_execute_long_fork(t_process **process, t_global *global_data)
{
	t_process	*dup_process;
	int			dir_arg;

	dir_arg = ft_extract_argument_dir_short(global_data, process, 1);
	dup_process =
		ft_duplicate_process(*process,
			ft_euclidean_mod((*process)->process_cursor + dir_arg,
				MEM_SIZE), global_data);
	dup_process->next = global_data->processes;
	global_data->processes = dup_process;
}
