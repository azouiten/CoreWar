/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 23:54:53 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/10 06:13:11 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

int			ft_arg_size(int arg, int current_op_index)
{
	if (arg == IND_CODE)
		return (IND_SIZE);
	if (arg == REG_CODE)
		return (1);
	if (arg == DIR_CODE)
	{
		if (!g_op_tab[current_op_index].t_dir_size)
			return (DIR_SIZE);
		else
			return (DIR_SIZE / 2);
	}
	return (0);
}
