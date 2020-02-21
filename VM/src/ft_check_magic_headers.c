/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_magic_headers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 03:40:36 by magoumi           #+#    #+#             */
/*   Updated: 2020/02/21 22:52:43 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

static void		ft_error_adjust(int *i, int *validity, int error,
		t_global *global_data)
{
	*validity = 0;
	if (error == 1)
		ft_manage_error(global_data, OPEN_FAIL, *i, 0);
	if (error == 2)
		ft_manage_error(global_data, READ_FAIL, *i, 0);
	if (error == 3)
		ft_manage_error(global_data, MAGIC_HEADER_FAIL, *i, 0);
	if (error != 3)
		*i = *i + 1;
}

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
			ft_error_adjust(&i, &data->champions[i].validity, 1, data);
			continue ;
		}
		ret = read(data->champions[i].fd, magic_header, 4);
		if (ret <= 0)
		{
			ft_error_adjust(&i, &data->champions[i].validity, 2, data);
			continue ;
		}
		if (!ft_cmp_magic_header(magic_header))
			ft_error_adjust(&i, &data->champions[i].validity, 3, data);
		i++;
	}
}
