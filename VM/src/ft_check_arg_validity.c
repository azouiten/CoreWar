/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg_validity.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 11:52:06 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/16 19:47:22 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

int	ft_check_arg_validity(int arg, int arg_num, int current_op_index)
{
	int	tab[3];

	if (arg == 0)
		return (0);
	tab[0] = 1;
	tab[1] = 2;
	tab[2] = 4;
	if (arg_num == 0)
	{
		if (!(tab[arg - 1] & g_op_tab[current_op_index].tab[0]))
			return (0);
	}
	else if (arg_num == 1)
	{
		if (!(tab[arg - 1] & g_op_tab[current_op_index].tab[1]))
			return (0);
	}
	else if (arg_num == 2)
	{
		if (!(tab[arg - 1] & g_op_tab[current_op_index].tab[2]))
			return (0);
	}
	return (1);
}
