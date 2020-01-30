/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_live.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 21:45:10 by ohachim           #+#    #+#             */
/*   Updated: 2020/01/30 09:49:22 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

static int	ft_extract_argument(t_global *global_data, t_process **process)
{
	t_hexa		live_union;
	int		byte_distance;
	int		cn;

	byte_distance = 1;
	cn = DIR_SIZE - 1;
	while (cn >= 0)
	{
		live_union.buf[cn] = global_data->arena[ft_euclidean_mod(((*process)->process_cursor + byte_distance), MEM_SIZE)];
		byte_distance++;
		cn--;
	}
	return (live_union.value);
}

void	ft_execute_live(t_process **process, t_global *global_data)
{
	int	live_arg_value;

	live_arg_value = ft_extract_argument(global_data, process);
	(*process)->last_live_cycle = global_data->cycle_since_start; // Maybe meant for an all time cycle;
	(*process)->live_declared = 1; // Must reset this.
	global_data->number_lives_declared++;
	if (live_arg_value == (*process)->registries[0]) // Maybe add varible to champion struct to know if it's alive.
		global_data->last_live_player = global_data->champions[(live_arg_value * -1) - 1];
}
