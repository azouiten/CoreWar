/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_cpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 09:39:57 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/24 19:26:38 by melalj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

void			ft_arena_cpy(t_global *global_data, int cpy_to, int to_cpy,
				t_process *process)
{
	t_hexa	store_hexa;
	int		cn;

	cn = 3;
	store_hexa.value = to_cpy;
	while (cn >= 0)
	{
		global_data->arena[ft_euclidean_mod(cpy_to, MEM_SIZE)] =
			store_hexa.buf[cn];
		global_data->visu_arena[ft_euclidean_mod(cpy_to, MEM_SIZE)].v = 500;
		global_data->visu_arena[ft_euclidean_mod(cpy_to, MEM_SIZE)].byte = store_hexa.buf[cn];
		global_data->visu_arena[ft_euclidean_mod(cpy_to, MEM_SIZE)].color = process->carriage_number;
		cpy_to++;
		cn--;
	}
}
