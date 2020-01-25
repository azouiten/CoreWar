/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_ind_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 00:41:49 by ohachim           #+#    #+#             */
/*   Updated: 2020/01/24 23:45:59 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

int	ft_get_ind_value(t_global *global_data, int adress)
{
	t_hexa		ind_union;

	ind_union.buf[3] = global_data->arena[adress];
	ind_union.buf[2] = global_data->arena[adress + 1];
	ind_union.buf[1] = global_data->arena[adress + 2];
	ind_union.buf[0] = global_data->arena[adress + 3];
	return (ind_union.value);
}
