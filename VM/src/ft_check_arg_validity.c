/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg_validity.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 11:52:06 by ohachim           #+#    #+#             */
/*   Updated: 2020/01/15 12:15:58 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

int	ft_check_arg_validity(int arg, int position, int current_op_index) // Care for garbage values.
{
	if (position == 1)
	{
		if (!(arg & op_tab[current_op_index].tab[0]))
			return (0);
	}
	else if (position == 3)
	{
		if (!(arg & op_tab[current_op_index].tab[1]))
			return (0);
	}
	else if (position == 5)	
	{
		if (!(arg & op_tab[current_op_index].tab[2]))
			return (0);
	}
	return (1);
}
