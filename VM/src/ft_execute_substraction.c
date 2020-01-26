/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_substraction.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 02:10:54 by ohachim           #+#    #+#             */
/*   Updated: 2020/01/26 14:14:38 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

void	ft_execute_substraction(t_process **process, t_global *global_data)
{
	int	first_reg;
	int	second_reg;
	int	third_reg;

	// Hopefully the argument check works fine, must check later.
	first_reg = global_data->arena[((*process)->process_cursor + 2) % MEM_SIZE];
	second_reg = global_data->arena[((*process)->process_cursor + 3) % MEM_SIZE];
	third_reg = global_data->arena[((*process)->process_cursor + 4) % MEM_SIZE];
	if (first_reg < 1 || first_reg > REG_NUMBER)
		return ;
	if (second_reg < 1 || second_reg > REG_NUMBER)
		return ;
	if (third_reg < 1 || third_reg > REG_NUMBER)
		return ;
	(*process)->registries[third_reg - 1] = (*process)->registries[first_reg - 1] - (*process)->registries[second_reg - 1];
	if ((*process)->registries[third_reg - 1])
		(*process)->carry = 0;
	else
		(*process)->carry = 1;
}
