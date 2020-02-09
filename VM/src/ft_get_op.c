/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 03:57:22 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/09 05:43:00 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

static void			ft_execute_op(t_global *global_data, t_process **process)
{
	int				arg_type;
	int				fail;

	fail = 0;
	if (op_tab[(*process)->current_op - 1].arguments)
		fail = ft_count_dodge_bytes(global_data, process, 0, 0);
	else
	{
		(*process)->arg[0] = op_tab[(*process)->current_op - 1].tab[0];
		if (!ft_check_registries(process, 1, 0, global_data))
			fail = 1;
		(*process)->bytes_to_next_op =
			ft_arg_size(op_tab[(*process)->current_op - 1].tab[0],
			(*process)->current_op - 1) + 1;
	}
	if (!fail)
		ft_execute_hq(process, global_data);
	if (!(*process)->carry || (*process)->current_op != 9
		|| ((*process)->current_op == 9 && (*process)->carry && fail))
		(*process)->process_cursor = ((*process)->process_cursor
		+ (*process)->bytes_to_next_op) % MEM_SIZE;
	(*process)->current_op = -1;
}

static void			ft_get_new_op(t_global *global_data, t_process **process)
{
	(*process)->current_op = global_data->arena[(*process)->process_cursor];
	if ((*process)->current_op > 16 || ((*process)->current_op < 1))
	{
		(*process)->cycles_till_op = 0;
		(*process)->process_cursor = ((*process)->process_cursor + 1)
										% MEM_SIZE;
	}
	else
		(*process)->cycles_till_op = op_tab[(*process)->current_op - 1].cost;
}

void				ft_get_op(t_global *global_data)
{
	t_process		*temp_process;

	global_data->all_time_cycles += 1;
	temp_process = global_data->processes;
	while (temp_process)
	{
		if (!temp_process->alive)
		{
			temp_process = temp_process->next;
			continue ;
		}
		if (temp_process->cycles_till_op == 0)
			ft_get_new_op(global_data, &temp_process);
		if (temp_process->cycles_till_op > 0)
			temp_process->cycles_till_op -= 1;
		if (temp_process->cycles_till_op == 0
			&& temp_process->current_op <= 16 && temp_process->current_op >= 1)
			ft_execute_op(global_data, &temp_process);
		temp_process = temp_process->next;
	}
}
