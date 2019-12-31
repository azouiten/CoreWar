/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 03:57:22 by ohachim           #+#    #+#             */
/*   Updated: 2019/12/31 04:10:50 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

void	ft_get_op(t_global *global_data)
{
	t_process	*temp_process;
	
	temp_process = global_data->processes;
	while (temp_process)
	{
		if (temp_process->cycle_till_op == 0)
		{
			ft_get_new_op(global_process, &temp_process);
			return ;
		}
		/* Where do we decrement temp_process->cycle*/
		temp_process->cycle -= 1;
		if (!(temp_process->cycle))
		{
			ft_execute_op(global_data, &temp_process);
			return ;
		}
	}
}
