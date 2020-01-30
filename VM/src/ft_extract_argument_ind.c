/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_argument_ind.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 01:09:14 by ohachim           #+#    #+#             */
/*   Updated: 2020/01/26 14:17:49 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

int	ft_extract_argument_ind(t_global *global_data, t_process **process, int byte_distance)
{
	t_hexa	v_union;

	v_union.buf[1] = global_data->arena[((*process)->process_cursor + byte_distance) % MEM_SIZE];
	v_union.buf[0] = global_data->arena[((*process)->process_cursor + byte_distance + 1) % MEM_SIZE];
	return (v_union.short_value);
}