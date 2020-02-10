/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duplicate_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 09:55:47 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/10 05:24:28 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

t_process		*ft_duplicate_process(t_process *process,
					int adress, t_global *global_data)
{
	t_process	*temp;
	int			count;

	count = 0;
	if (!(temp = (t_process*)malloc(sizeof(t_process))))
		ft_manage_error(global_data, MALLOC_FAIL, -1, 1);
	temp->carriage_number = process->carriage_number;
	temp->alive = 1;
	temp->carry = process->carry;
	temp->current_op = 0;
	temp->last_live_cycle = process->last_live_cycle;
	temp->cycles_till_op = 0;
	temp->process_cursor = adress;
	temp->bytes_to_next_op = 0;
	temp->arg[0] = 0;
	temp->arg[1] = 0;
	temp->arg[2] = 0;
	temp->live_declared = process->live_declared;
	temp->next = NULL;
	while (count < REG_NUMBER)
	{
		temp->registries[count] = process->registries[count];
		count++;
	}
	return (temp);
}
