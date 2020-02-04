/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_arena.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 18:25:14 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/04 23:27:01 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

void	ft_fill_arena(t_global *global_data)
{
	int	i;

	i = 0;
	while (i < global_data->champion_count)
	{
		if (global_data->champions[i].validity)
			ft_memcpy(
				&global_data->arena[global_data->champions[i].starting_point],
				global_data->champions[i].exec_code,
				global_data->champions[i].hex_code_size);
		i++;
	}
}
