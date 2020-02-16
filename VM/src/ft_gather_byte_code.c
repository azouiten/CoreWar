/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gather_byte_code.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 12:23:20 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/16 19:55:29 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

static void		ft_extract_name(t_global *global_data, int i, int cn)
{
	int			ret;

	if (!(global_data->champions[i].byte_name =
		(unsigned char*)malloc((sizeof(unsigned char) *
			PROG_NAME_LENGTH) + 1)))
		ft_manage_error(global_data, MALLOC_FAIL, -1, 1);
	global_data->champions[i].byte_name[PROG_NAME_LENGTH] = '\0';
	if (!(ret = read(global_data->champions[i].fd,
		global_data->champions[i].byte_name, PROG_NAME_LENGTH)))
	{
		ft_manage_error(global_data, DATA_LACK, i, 0);
		return ;
	}
	if (ret < 0)
	{
		ft_manage_error(global_data, READ_FAIL, i, 0);
		return ;
	}
}

static void		ft_extract_comment(t_global *global_data, int i, int cn)
{
	int			ret;

	if (!(global_data->champions[i].comment =
		(unsigned char*)malloc((sizeof(unsigned char) *
			COMMENT_LENGTH) + 1)))
		ft_manage_error(global_data, MALLOC_FAIL, -1, 1);
	global_data->champions[i].comment[COMMENT_LENGTH] = '\0';
	if (global_data->champions[i].validity == 0)
		return ;
	if (!(ret = read(global_data->champions[i].fd,
		global_data->champions[i].comment, COMMENT_LENGTH)))
	{
		ft_manage_error(global_data, DATA_LACK, i, 0);
		return ;
	}
	if (ret < 0)
	{
		ft_manage_error(global_data, READ_FAIL, i, 0);
		return ;
	}
}

static void		ft_extract_exec_code_size(t_global *global_data, int i)
{
	char		c;
	t_hexa		uni_hexa;
	int			ret;

	uni_hexa.value = 0;
	if (global_data->champions[i].validity == 0)
		return ;
	if (!(ret = read(global_data->champions[i].fd, uni_hexa.buf, 4)))
		ft_manage_error(global_data, DATA_LACK, i, 1);
	if (ret < 0)
	{
		ft_manage_error(global_data, READ_FAIL, i, 0);
		return ;
	}
	c = uni_hexa.buf[0];
	uni_hexa.buf[0] = uni_hexa.buf[3];
	uni_hexa.buf[3] = c;
	c = uni_hexa.buf[1];
	uni_hexa.buf[1] = uni_hexa.buf[2];
	uni_hexa.buf[2] = c;
	global_data->champions[i].hex_code_size = uni_hexa.value;
	if (uni_hexa.value > CHAMP_MAX_SIZE)
		ft_manage_error(global_data, BIG_CHAMP, i, 1);
}

static void		ft_extract_exec_code(t_global *global_data, int i)
{
	int			cn;
	int			ret;

	cn = 0;
	if (global_data->champions[i].hex_code_size == 0)
	{
		ft_manage_error(global_data, EXEC_CODE_SIZE_ZERO, i, 0);
		return ;
	}
	if (!(global_data->champions[i].exec_code =
	(unsigned char*)ft_strnew(global_data->champions[i].hex_code_size)))
		ft_manage_error(global_data, MALLOC_FAIL, -1, 1);
	if (!(ret = read(global_data->champions[i].fd,
		global_data->champions[i].exec_code,
			global_data->champions[i].hex_code_size)))
		ft_manage_error(global_data, DATA_LACK, i, 0);
	else if (ret < 0)
		ft_manage_error(global_data, READ_FAIL, i, 0);
}

void			ft_gather_byte_code(t_global *global_data)
{
	int			i;

	i = 0;
	while (i < global_data->champion_count)
	{
		global_data->champions[i].hex_code_size = 0;
		if (global_data->champions[i].validity == 0)
		{
			i++;
			continue ;
		}
		ft_extract_name(global_data, i, 0);
		if (!ft_dodge_bytes(global_data, i, 4, 1) && (i = i + 1))
			continue ;
		ft_extract_exec_code_size(global_data, i);
		ft_extract_comment(global_data, i, 0);
		if (!ft_dodge_bytes(global_data, i, 4, 2) && (i = i + 1))
			continue ;
		ft_extract_exec_code(global_data, i);
		i++;
	}
}
