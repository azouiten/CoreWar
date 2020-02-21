/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dodge_bytes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 23:59:36 by magoumi           #+#    #+#             */
/*   Updated: 2020/02/18 23:59:42 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

int			ft_dodge_bytes(t_global *data, int i, int bytes)
{
	int		ret;
	char	buf[4];

	if (read(data->champions[i].fd, buf, bytes) <= 0)
	{
		data->champions[i].validity = 0;
		ft_printf("Error: Can't read NULL bytes in [%s].\n",
		data->champions[i].name);
		return (0);
	}
	return (1);
}
