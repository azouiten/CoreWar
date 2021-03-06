/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_addition.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 02:10:54 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/10 05:27:44 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

void	ft_execute_addition(t_process **process, t_global *global_data)
{
	int	first_reg;
	int	second_reg;
	int	third_reg;

	first_reg =
		global_data->arena[ft_euclidean_mod(((*process)->process_cursor + 2),
			MEM_SIZE)];
	second_reg =
		global_data->arena[ft_euclidean_mod(((*process)->process_cursor + 3),
			MEM_SIZE)];
	third_reg =
		global_data->arena[ft_euclidean_mod(((*process)->process_cursor + 4),
			MEM_SIZE)];
	if (first_reg < 1 || first_reg > REG_NUMBER
		|| second_reg < 1 || second_reg > REG_NUMBER
			|| third_reg < 1 || third_reg > REG_NUMBER)
		return ;
	(*process)->registries[third_reg - 1] =
		(*process)->registries[first_reg - 1] +
			(*process)->registries[second_reg - 1];
	if ((*process)->registries[third_reg - 1])
		(*process)->carry = 0;
	else
		(*process)->carry = 1;
}
