/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_byts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 22:05:51 by azouiten          #+#    #+#             */
/*   Updated: 2020/01/26 19:02:50 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_put_name(t_data *data)
{
	int	i;

	i = 0;
	while (data->ltoken->piece[i])
	{
		write(data->fd, &data->ltoken->piece[i], 1);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		write(data->fd, $0, 1);
		i++;
	}
}

void	ft_write_cmds(t_data *data, int t)
{
	if (!ft_strcmp(data->ltoken, NAME_CMD_STRING))
		ft_put_name(data);
	else if (!ft_strcmp(data->ltoken, COMMENT_CMD_STRING))
		ft_put_cmnt(data);
}

void	ft_identify(t_data *data)
{
	int t;

	t = 0;
	if (ft_check_cmd(data))
		ft_write_cmd(data, 0);
	else if ((t = ft_check_inst(data)) != -1)
		ft_write_inst(data, t);
	else if (data->ltoken->piece[0] != '\0' && data->ltoken->piece[0] != '\n')
		ft_exit(data, data->ltoken->line);
}

void	ft_write_file(t_data *data)
{
	data->file = ft_strjoin(data->file, "or");
	if (!(data->fd = open(data->file, O_CREAT, O_RDWR)))
		ft_exit(data, 1);
	ft_put_magic(data);
	ft_write_cmds(data, 1);
	ft_put_size(data);
	ft_write_cmds(data, 1);
	while (data->ltoken)
	{
		ft_identify(data);
		data->ltoken = data->ltoken->next;
	}
}
