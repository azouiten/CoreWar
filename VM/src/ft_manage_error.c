/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 08:19:44 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/10 06:08:22 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

static void	ft_init_error_buf(t_global *global_data)
{
	if (!(global_data->error_buf =
			(char**)malloc(sizeof(char*) * TOTAL + 1)))
		ft_manage_error(global_data, MALLOC_FAIL, -1, 0);
	global_data->error_buf[ZERO_CHAMPION] = "0 Champions";
	global_data->error_buf[TOO_MANY_PLAYERS] = "Too many players";
	global_data->error_buf[MALLOC_FAIL] = "Malloc fail";
	global_data->error_buf[OPEN_FAIL] = "Unable to open file";
	global_data->error_buf[READ_FAIL] = "Unable to read file";
	global_data->error_buf[MAGIC_HEADER_FAIL] = "Magic header is not valid in";
	global_data->error_buf[DATA_LACK] = "Not enough data in";
	global_data->error_buf[EXEC_CODE_SIZE_FAIL] = \
		"Unable to extract exec_code_size from";
	global_data->error_buf[EXEC_CODE_SIZE_ZERO] = "Exec code size is 0";
	global_data->error_buf[EXEC_CODE_SIZE_WRONG] = "Exec code size is wrong";
	global_data->error_buf[ZERO_VALID_CHAMPION] = "0 Valid champions";
	global_data->error_buf[TOTAL] = NULL;
}

void		ft_manage_error(t_global *global_data, int error_num,
			int champion_index, int quit)
{
	if (!global_data->error_buf)
		ft_init_error_buf(global_data);
	ft_printf("Error: %s", global_data->error_buf[error_num]);
	if (champion_index >= 0)
	{
		global_data->champions[champion_index].validity = 0;
		close(global_data->champions[champion_index].fd);
		global_data->champions[champion_index].fd = -1;
		ft_printf(" [%s].\n", global_data->champions[champion_index].name);
	}
	else
		ft_printf(".\n");
	if (quit == 0)
		return ;
	ft_free_data(global_data);
	exit(1);
}
