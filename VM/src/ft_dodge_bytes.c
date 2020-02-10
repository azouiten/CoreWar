/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dodge_bytes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 04:16:50 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/10 05:20:32 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

int			ft_dodge_bytes(t_global *global_data, int i, int bytes,
				int error_num)
{
	int		ret;
	char	buf[4];

	if (read(global_data->champions[i].fd, buf, bytes) <= 0)
	{
		global_data->champions[i].validity = 0;
		ft_printf("Error: Can't read NULL bytes [%d] in [%s].\n",
				error_num, global_data->champions[i].name);
		return (0);
	}
	return (1);
}
