/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg_validity.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 11:52:06 by ohachim           #+#    #+#             */
/*   Updated: 2020/01/23 07:13:35 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

int	ft_check_arg_validity(int arg, int arg_num, int current_op_index) // Care for garbage values.
{
	int	tab[3];

	tab[0] = 1;
	tab[1] = 2;
	tab[2] = 4;
	// Might need to switch arguments order.
	if (arg_num == 0)
	{
		if (!(tab[arg - 1] & op_tab[current_op_index].tab[0]))
			return (0);
		ft_printf("%d-----%d\n", tab[arg - 1], op_tab[current_op_index].tab[0]);
	}
	else if (arg_num == 1)
	{
		if (!(tab[arg - 1] & op_tab[current_op_index].tab[1]))
			return (0);
		ft_printf("%d-----%d\n", tab[arg - 1], op_tab[current_op_index].tab[1]);
	}
	else if (arg_num == 2)	
	{
		if (!(tab[arg - 1] & op_tab[current_op_index].tab[2]))
			return (0);
	}
	ft_printf("does it go here\n");
	return (1);
}
