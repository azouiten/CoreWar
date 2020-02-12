/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_arena.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:18:42 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/12 11:24:52 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

void	ft_copy_arena(t_global *global_data)
{
	int	i;

	i = 0;
	if (!global_data->arena_dump)
	{
		if (!(global_data->arena_dump = (unsigned char*)malloc(sizeof(unsigned char) * MEM_SIZE)))
			ft_manage_error(global_data, MALLOC_FAIL, -1, 1);
	}
	while (i < MEM_SIZE)
	{
		global_data->arena_dump[i] = global_data->arena[i];
		i++;
	}
}
