/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_magic_headers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 03:40:36 by magoumi           #+#    #+#             */
/*   Updated: 2020/02/21 19:11:21 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

static int		ft_cmp_magic_header(unsigned char *magic_header)
{
	if (magic_header[0] != 0x0
			|| magic_header[1] != 0xea
			|| magic_header[2] != 0x83
			|| magic_header[3] != 0xf3)
		return (0);
	return (1);
}

void	ft_check_magic_headers(t_global *data, int i, int ret)
{
	unsigned char	magic_header[5];

	while (i < data->champion_count)
	{
		data->champions[i].fd = open(data->champions[i].name, O_RDONLY);
		if (data->champions[i].fd < 0)
		{
			data->champions[i].validity = 0;
			continue ;
		}
		ret = read(data->champions[i].fd, magic_header, 4);
		if (ret <= 0)
		{
			data->champions[i].validity = 0;
			continue ;
		}
		if (!ft_cmp_magic_header(magic_header))
			data->champions[i].validity = 0;
		i++;
	}
}
