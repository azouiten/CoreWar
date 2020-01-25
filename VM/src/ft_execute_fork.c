/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_fork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 09:48:27 by ohachim           #+#    #+#             */
/*   Updated: 2020/01/25 10:11:28 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

void	ft_execute_fork(t_process **process, t_global *global_data)
{
	t_process	*dup_process;
	int		dir_arg;

	dir_arg = ft_extract_argument_dir_short(global_data, process, 1);
	dup_process = ft_duplicate_process(*process, ((*process)->process_cursor + dir_arg) % IDX_MOD, global_data);
	dup_process->next = global_data->processes;
	global_data->processes = dup_process;
}
