/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dodge_bytes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 04:16:50 by ohachim           #+#    #+#             */
/*   Updated: 2019/12/24 04:32:13 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

int	ft_dodge_bytes(t_global *global_data, int i, int bytes, int error_num)
{
	int	ret;
	char	buf[4];

	if (read(global_data->champions[i].fd, buf, bytes) <= 0) // Will turn into a dodge function.
	{
		global_data->champions[i].validity = 0;
		ft_printf("Error: Can't read NULL bytes [%d] in [%s].\n",
		        error_num, global_data->champions[i].name);
		return (0);
	}
	return (1);
}
