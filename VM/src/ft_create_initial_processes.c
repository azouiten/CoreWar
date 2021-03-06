/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_initial_processes.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 22:11:33 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/04 23:20:53 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

static t_process	*ft_create_process_node(t_global *global_data,
					int i, int real_index, int count)
{
	t_process		*temp;

	if (!(temp = (t_process*)malloc(sizeof(t_process))))
		ft_manage_error(global_data, MALLOC_FAIL, -1, 1);
	temp->carriage_number = real_index;
	temp->alive = 1;
	temp->carry = 0;
	temp->current_op = 0;
	temp->last_live_cycle = -1;
	temp->cycles_till_op = 0;
	temp->process_cursor = global_data->champions[i].starting_point;
	temp->bytes_to_next_op = 0;
	temp->arg[0] = 0;
	temp->arg[1] = 0;
	temp->arg[2] = 0;
	temp->live_declared = 0;
	temp->next = NULL;
	temp->registries[0] = (real_index + 1) * -1;
	while (count < REG_NUMBER)
	{
		temp->registries[count] = 0;
		count++;
	}
	return (temp);
}

static void			ft_add_process(t_global *global_data, int i, int real_index)
{
	t_process		*temp;

	temp = ft_create_process_node(global_data, i, real_index, 1);
	if (global_data->processes == NULL)
		global_data->processes = temp;
	else
	{
		temp->next = global_data->processes;
		global_data->processes = temp;
	}
}

void				ft_create_initial_processes(t_global *global_data)
{
	int				real_index;
	int				i;

	real_index = 0;
	i = 0;
	while (i < global_data->champion_count)
	{
		if (global_data->champions[i].validity)
			ft_add_process(global_data, i, real_index);
		i++;
		real_index++;
	}
}
