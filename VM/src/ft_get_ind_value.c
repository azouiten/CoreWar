/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_ind_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 00:41:49 by ohachim           #+#    #+#             */
/*   Updated: 2020/01/23 06:38:42 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

int	ft_get_ind_value(t_global *global_data, int adress)
{
	t_hexa		ind_union;
	int		cn;

	cn = 3;
	while (cn >= 0)
	{
		ind_union.buf[cn] = global_data->arena[adress];
		cn--;
		adress++;
	}
	return (ind_union.value);
}
