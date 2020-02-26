/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gather_byte_code.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 04:14:09 by magoumi           #+#    #+#             */
/*   Updated: 2020/02/25 16:31:45 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

static void	ft_extract_name(t_global *data, int i)
{
	int	ret;

	if (data->champions[i].validity == 0)
		return ;
	if (!(data->champions[i].byte_name = (unsigned char*)malloc(
		(sizeof(unsigned char) * PROG_NAME_LENGTH) + 1)))
		ft_manage_error(data, MALLOC_FAIL, -1, 1);
	data->champions[i].byte_name[PROG_NAME_LENGTH] = '\0';
	if (!(ret = read(data->champions[i].fd,
		data->champions[i].byte_name, PROG_NAME_LENGTH)) || ret < 0)
		ft_manage_error(data, READ_FAIL, i, 0);
}

static void	ft_extract_exec_code_size(t_global *data, int i)
{
	char		c;
	t_hexa		uni_hexa;
	int			ret;

	uni_hexa.value = 0;
	if (data->champions[i].validity == 0)
		return ;
	ret = read(data->champions[i].fd, uni_hexa.buf, 4);
	if (ret <= 0)
	{
		ft_manage_error(data, READ_FAIL, i, 0);
		return ;
	}
	c = uni_hexa.buf[0];
	uni_hexa.buf[0] = uni_hexa.buf[3];
	uni_hexa.buf[3] = c;
	c = uni_hexa.buf[1];
	uni_hexa.buf[1] = uni_hexa.buf[2];
	uni_hexa.buf[2] = c;
	data->champions[i].hex_code_size = uni_hexa.value;
	if (uni_hexa.value > CHAMP_MAX_SIZE)
		ft_manage_error(data, BIG_CHAMP, i, 1);
}

static void	ft_extract_comment(t_global *data, int i)
{
	int			ret;

	if (!(data->champions[i].validity))
		return ;
	if (!(data->champions[i].comment =
		(unsigned char*)malloc((sizeof(unsigned char) *
			COMMENT_LENGTH) + 1)))
		ft_manage_error(data, MALLOC_FAIL, -1, 1);
	data->champions[i].comment[COMMENT_LENGTH] = '\0';
	if (!(ret = read(data->champions[i].fd,
		data->champions[i].comment, COMMENT_LENGTH)))
	{
		ft_manage_error(data, DATA_LACK, i, 0);
		return ;
	}
	if (ret < 0)
	{
		ft_manage_error(data, READ_FAIL, i, 0);
		return ;
	}
}

static void	ft_extract_exec_code(t_global *data, int i)
{
	int			cn;
	int			ret;

	cn = 0;
	if (data->champions[i].validity == 0)
		ft_manage_error(data, EXEC_CODE_SIZE_ZERO, i, 0);
	if (!(data->champions[i].exec_code =
	(unsigned char*)ft_strnew(data->champions[i].hex_code_size)))
		ft_manage_error(data, MALLOC_FAIL, -1, 1);
	if (!(ret = read(data->champions[i].fd,
		data->champions[i].exec_code,
			data->champions[i].hex_code_size)))
		ft_manage_error(data, DATA_LACK, i, 0);
	else if (ret < 0)
		ft_manage_error(data, READ_FAIL, i, 0);
}

void		ft_gather_byte_code(t_global *data)
{
	int	i;

	i = 0;
	while (i < data->champion_count)
	{
		data->champions[i].hex_code_size = 0;
		if (!data->champions[i].validity)
		{
			i++;
			continue ;
		}
		ft_extract_name(data, i);
		if (!ft_dodge_bytes(data, i, 4) && (i = i + 1))
			continue ;
		ft_extract_exec_code_size(data, i);
		ft_extract_comment(data, i);
		if (!ft_dodge_bytes(data, i, 4) && (i = i + 1))
			continue ;
		ft_extract_exec_code(data, i);
		i++;
	}
}
