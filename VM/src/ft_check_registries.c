/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_registries.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 00:02:17 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/16 19:46:26 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

int			ft_check_registries(t_process **process, int reg_index,
			int arg_num, t_global *global_data)
{
	int				reg;

	reg = 0;
	if ((*process)->arg[arg_num] != REG_CODE)
		return (1);
	reg = global_data->arena[((*process)->process_cursor + reg_index)
			% MEM_SIZE];
	if (reg < 1 || reg > REG_NUMBER)
		return (0);
	return (1);
}
