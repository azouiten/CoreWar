/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_byts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 22:05:51 by azouiten          #+#    #+#             */
/*   Updated: 2020/02/08 05:08:15 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_put_str(t_data *data, int s)
{
	int	i;
	int	v;
	char	*tmp;

	v = 0;
	i = 0;
	data->ltoken = data->ltoken->next;
	tmp = data->ltoken->piece;
	data->ltoken->piece = ft_strsub(tmp, 1, ft_strlen(tmp) - 2);
	free(tmp);
	while (data->ltoken && data->ltoken->piece[i])
	{
		write(data->fd, &data->ltoken->piece[i], 1);
		i++;
	}
	while (i < s)
	{
		write(data->fd, &v, 1);
		i++;
	}
	write(data->fd, &v, 4);
	/*if (s == PROG_NAME_LENGTH)
		ft_put_size(data);*/
	data->ltoken = data->ltoken->next->next;
}

void	ft_skip_line(t_data *data)
{
	while (data->ltoken && data->ltoken->piece[0] != '\n')
		data->ltoken = data->ltoken->next;
	data->ltoken = data->ltoken->next;
}

void	ft_put_magic(t_data *data)
{
	int	i;
	int	magic;
	int	magic_buff;

	i = 0;
	magic = COREWAR_EXEC_MAGIC;
	magic_buff = magic;
	while (i < 4)
	{
		magic = magic>>(8 * (4 - i - 1));
		write(data->fd, &magic, 1);
		magic = magic_buff;
		i++;
	}
}

void	ft_write_dir(t_data *data, int size)
{
	int	value;
	int	value_buff;
	int	i;

	i = 1;
	if (!(value = ft_atoi(data->ltoken->piece)))
	{
		ft_exit(data, data->ltoken->line);
	}
	if (value < 0)
	{
		value *= -1;
		value = ~value;
		value += 1;
	}
	value_buff = value;
	while (i <= size)
	{
		value = value>>(8 * (size - i - 1));
		write(data->fd, &value, 1);
		value = value_buff;
		i++;
	}
}

void	ft_write_reg(t_data *data)
{
	int	value;

	value = ft_atoi(data->ltoken->piece + 1);
	write(data->fd, &value, 1);
}

void	ft_write_ind(t_data *data)
{
	int	value;
	int	value_buff;
	int	i;

	value = ft_atoi(data->ltoken->piece);
	i = 1;
	if (value < 0)
	{
		value *= -1;
		value = ~value;
		value += 1;
	}
	value_buff = value;
	while (i <= 2)
	{
		value = value>>(8 * (2 - i - 1));
		write(data->fd, &value, 1);
		value = value_buff;
		i++;
	}
}

void	ft_write_inst(t_data *data, int index)
{
	int i;
	int	arg_code;
	t_token	*tmp;
	int	res;

	i = 0;
	arg_code = 0;
	data->ltoken = data->ltoken->next;
	tmp = data->ltoken;
	while (data->ltoken && op_tab[index].argc > i)
	{
		arg_code = arg_code | ft_identify_arg(data);
		arg_code = arg_code<<2;
		data->ltoken = data->ltoken->next;
		if (data->ltoken->piece[0] == ',')
			data->ltoken = data->ltoken->next;
		i++;
	}
	data->ltoken = tmp;
	i = 0;
	while (data->ltoken && op_tab[index].argc > i)
	{
		ft_putstr(data->ltoken->piece);
		res = ft_identify_arg(data);
		if (res == DIR_CODE)
			ft_write_dir(data, (op_tab[index].dir_size == 1) ? 2 : 4);
		else if (res == REG_CODE)
			ft_write_reg(data);
		else
			ft_write_ind(data);
		data->ltoken = data->ltoken->next;
		if (data->ltoken->piece[0] == ','){
			data->ltoken = data->ltoken->next;
		}
		i++;
	}
}

void	ft_write_cmd(t_data *data, int t)
{
	if (t != 1){
		ft_skip_line(data);}
	else if (!ft_strcmp(data->ltoken->piece, NAME_CMD_STRING)){
		ft_put_str(data, PROG_NAME_LENGTH);}
	else if (!ft_strcmp(data->ltoken->piece, COMMENT_CMD_STRING)){
		ft_put_str(data, COMMENT_LENGTH);}
}

void	ft_identify(t_data *data)
{
	int index;

	index = 0;
	if (ft_check_cmd(data))
		ft_write_cmd(data, 0);
	else if ((index = ft_check_inst(data)) != -1)
		ft_write_inst(data, index);
	else if (data->ltoken->piece[0] != '\0'
			&& data->ltoken->piece[0] != '\n'){
		ft_exit(data, data->ltoken->line);
	}
}

void	ft_write_file(t_data *data)
{
	data->file = ft_strjoin(data->file, "or");
	if (!(data->fd = open(data->file, O_CREAT | O_RDWR))){
		ft_exit(data, 1);
	}
	ft_put_magic(data);
	ft_write_cmd(data, 1);
	ft_write_cmd(data, 1);
	while (data->ltoken)
	{
		ft_identify(data);
		data->ltoken = data->ltoken->next;
		while (data->ltoken && data->ltoken->piece[0] == '\n')
			data->ltoken = data->ltoken->next;
	}
}
