/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arena.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:07:35 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/23 22:46:55 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

void		ft_print_arena(t_global *global_data, int xs)
{
	int		cn;
	int		mod;

	ft_print_affs(*global_data);
	cn = 0;
	mod = 0;
	while (cn < xs)
	{
		if ((mod == 0 || (mod == 64 && !(mod = 0))))
		{
			ft_printf("0x");
			ft_printf("%.4x : ", cn);
		}
		ft_printf("%.2x", global_data->arena_dump[cn]);
		mod++;
		if (mod == 64 && !(mod = 0))
			ft_printf(" \n", cn);
		else
			ft_printf(" ");
		cn++;
	}
	ft_free_data(global_data);
	exit(0);
}
