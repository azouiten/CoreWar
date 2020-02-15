/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg_validity.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 11:52:06 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/14 23:49:06 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

int	ft_check_arg_validity(int arg, int arg_num, int current_op_index)
{
	if (arg_num == 0)
	{
		if (!(arg & g_op_tab[current_op_index].tab[0]))
			return (0);
	}
	else if (arg_num == 1)
	{
		if (!(arg & g_op_tab[current_op_index].tab[1]))
			return (0);
	}
	else if (arg_num == 2)
	{
		if (!(arg & g_op_tab[current_op_index].tab[2]))
			return (0);
	}
	return (1);
}
