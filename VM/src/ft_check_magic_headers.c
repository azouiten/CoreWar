/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_magic_headers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 00:23:04 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/04 23:06:30 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

static void			ft_error_adjust(int *i, int *validity, int error,
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

static int			ft_cmp_magic_header(t_global *global_data,
		unsigned char *magic_header)
{
	if (magic_header[0] != 0x0
			|| magic_header[1] != 0xea
			|| magic_header[2] != 0x83
			|| magic_header[3] != 0xf3)
		return (0);
	return (1);
}

void				ft_check_magic_headers(t_global *global_data,
		int i, int ret)
{
	unsigned char	magic_header[5];

	while (i < global_data->champion_count)
	{
		global_data->champions[i].fd =
			open(global_data->champions[i].name, O_RDONLY);
		if (global_data->champions[i].fd < 0)
		{
			ft_error_adjust(&i,
			&global_data->champions[i].validity, 1, global_data);
			continue ;
		}
		ret = read(global_data->champions[i].fd, magic_header, 4);
		if (ret <= 0)
		{
			ft_error_adjust(&i,
			&global_data->champions[i].validity, 2, global_data);
			continue ;
		}
		if (!ft_cmp_magic_header(global_data, magic_header))
			ft_error_adjust(&i,
			&global_data->champions[i].validity, 3, global_data);
		i++;
	}
}
