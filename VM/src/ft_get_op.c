/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 03:57:22 by ohachim           #+#    #+#             */
/*   Updated: 2020/01/05 07:15:58 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

static void	ft_get_new_op(t_global *global_data, t_process **process)
{
	(*process)->current_op = global_data->arena[(*process)->process_cursor + 1];
	ft_printf("%x-----------\n", (*process)->current_op);
}

void	ft_get_op(t_global *global_data)
{
	t_process	*temp_process;
	
	temp_process = global_data->processes;
	while (temp_process)
	{
		ft_printf("hello\n");
		if (temp_process->cycles_till_op == 0)
			ft_get_new_op(global_data, &temp_process);
		/* Where do we decrement temp_process->cycle_till_op*/
		//temp_process->cycles_till_op -= 1;
		temp_process = temp_process->next;
	}
}
