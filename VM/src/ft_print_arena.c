/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arena.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:07:35 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/08 23:48:49 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

static int	ft_in_cursor(int cn, t_global *global_data)
{
	t_process	*temp;

	temp = global_data->processes;
	while (temp)
	{
		if (temp->process_cursor == cn && temp->alive)
			return (1);
		temp = temp->next;
	}
	return (0);
}


void    ft_print_arena(t_global *global_data, int xs, int cursor)
{
	int	cn;
	int	mod;

	cn = 0;
	mod = 0;
	while (cn < xs)
	{
		if ((mod == 0 && !(mod = 0)) || (mod == 64 && !(mod = 0)))
		{
			ft_printf("0x");
			ft_printf("%.4x : ", cn);
		}
		// if (ft_in_cursor(cn, global_data))
		// 	ft_printf("[%.2x]", global_data->arena[cn]);
		// else
		ft_printf("%.2x", global_data->arena[cn]);
		mod++;
		if (mod == 64 && !(mod = 0))
			ft_printf(" \n", cn);
		else
			ft_printf(" ");
		cn++;
	}
	ft_printf("\n");

}
