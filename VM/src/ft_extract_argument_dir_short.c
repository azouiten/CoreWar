/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_argument_dir_short.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 03:56:38 by ohachim           #+#    #+#             */
/*   Updated: 2020/01/25 03:57:00 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

int	ft_extract_argument_dir_short(t_global *global_data, t_process **process, int byte_distance)
{
	t_hexa	v_union;

	v_union.buf[1] = global_data->arena[(*process)->process_cursor + byte_distance];
	v_union.buf[0] = global_data->arena[(*process)->process_cursor + byte_distance + 1];
	return (v_union.short_value);
}
