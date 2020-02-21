/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gather_byte_code.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 04:14:09 by magoumi           #+#    #+#             */
/*   Updated: 2020/02/19 00:00:18 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

void	ft_extract_name(t_global *data, int i, int cn)
{
	int	ret;

	if (data->champions[i].validity == 0)
		return ;
	if (!(data->champions[i].byte_name = (unsigned char*)malloc(
		(sizeof(unsigned char) * PROG_NAME_LENGTH) + 1)))
		exit(1);
	data->champions[i].byte_name[PROG_NAME_LENGTH] = '\0';
	if (!(ret = read(data->champions[i].fd,
		data->champions[i].byte_name, PROG_NAME_LENGTH)) || ret < 0)
		data->champions[i].validity = 0;
}

void	ft_extract_exec_code_size(t_global *data, int i)
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
		data->champions[i].validity = 0;
		return ;
	}
	c = uni_hexa.buf[0];
	uni_hexa.buf[0] = uni_hexa.buf[3];
	uni_hexa.buf[3] = c;
	c = uni_hexa.buf[1];
	uni_hexa.buf[1] = uni_hexa.buf[2];
	uni_hexa.buf[2] = c;
	data->champions[i].hex_code_size = uni_hexa.value;
	if (uni_hexa.value > CHAMP_MAX_SIZE || !uni_hexa.value)
		data->champions[i].validity = 0;
}

void	ft_extract_comment(t_global *data, int i, int cn)
{
	int			ret;

	if (!(data->champions[i].validity))
		return ;
	if (!(data->champions[i].comment =
		(unsigned char*)malloc((sizeof(unsigned char) *
			COMMENT_LENGTH) + 1)))
		exit(1);
	data->champions[i].comment[COMMENT_LENGTH] = '\0';
	if (!(ret = read(data->champions[i].fd,
		data->champions[i].comment, COMMENT_LENGTH)))
	{
		data->champions[i].validity = 0;
		return ;
	}
	if (ret < 0)
	{
		data->champions[i].validity = 0;
		return ;
	}
}

void	ft_extract_exec_code(t_global *data, int i)
{
	int			cn;
	int			ret;

	cn = 0;
	if (data->champions[i].validity == 0)
		return ;
	if (!(data->champions[i].exec_code =
	(unsigned char*)ft_strnew(data->champions[i].hex_code_size)))
		exit(1);
	if (!(ret = read(data->champions[i].fd,
		data->champions[i].exec_code,
			data->champions[i].hex_code_size)))
		data->champions[i].validity = 0;
	else if (ret < 0)
		data->champions[i].validity = 0;
}

/*
*** name >> null bytes >> exec code size >> comment >> null >> exec code
*/

void	ft_gather_byte_code(t_global *data)
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
		ft_extract_name(data, i, 0);
		if (!ft_dodge_bytes(data, i, 4) && (i = i + 1))
			continue ;
		ft_extract_exec_code_size(data, i);
		ft_extract_comment(data, i, 0);
		if (!ft_dodge_bytes(data, i, 4) && (i = i + 1))
			continue ;
		ft_extract_exec_code(data, i);
		i++;
	}
}
