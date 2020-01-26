/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_or.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 02:43:20 by ohachim           #+#    #+#             */
/*   Updated: 2020/01/26 13:42:14 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

void	ft_execute_or(t_process **process, t_global *global_data)
{
	int	first_arg;
	int	second_arg;
	int	reg;
	int	dodge;

	dodge = 2;
	first_arg = ft_get_arg(process, global_data, &dodge, 0);
	second_arg = ft_get_arg(process, global_data, &dodge, 1);
	reg = global_data->arena[((*process)->process_cursor + dodge) % MEM_SIZE];
	(*process)->registries[reg - 1] = first_arg | second_arg;
	if ((*process)->registries[reg - 1])
		(*process)->carry = 0;
	else
		(*process)->carry = 1;
}
