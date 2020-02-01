/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_byts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 22:05:51 by azouiten          #+#    #+#             */
/*   Updated: 2020/02/01 21:24:27 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_put_str(t_data *data, int s)
{
	int	i;
	int	v;

	v = 0;
	i = 0;
	while (data->ltoken && data->ltoken->piece[i])
	{
		write(data->fd, &data->ltoken->piece[i], 1);
		i++;
	}
	write(data->fd, &v, s - i - 1);
	write(data->fd, &v, 4);
	/*if (s == PROG_NAME_LENGTH)
		ft_put_size(data);*/
}

void	ft_skip_line(t_data *data)
{
	while (data->ltoken && data->ltoken->piece[0] != '\n')
		data->ltoken = data->ltoken->next;
}

void	ft_put_magic(t_data *data)
{
	int	i;
	int	magic;

	i = 0;
	magic = COREWAR_EXEC_MAGIC;
	while (i < 4)
	{
		write(data->fd, &magic, 1);
		magic = magic>>8;
		i++;
	}
}

void	ft_write_dir(t_data *data, int size)
{
	int	value;
	int	i;

	i = 1;
	data->ltoken = data->ltoken->next;
	if (!(value = ft_atoi(data->ltoken->piece)))
	{

		write(1, "yes\n", 4);
		ft_exit(data, 0);
	}
	if (value < 0)
	{
		value *= -1;
		value = ~value;
		value += 1;
	}
	while (i <= size)
	{
		write(data->fd, &value, 1);
		value = value>>8;
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
	int	i;

	value = ft_atoi(data->ltoken->piece);
	i = 1;
	if (value < 0)
	{
		value *= -1;
		value = ~value;
		value += 1;
	}
	while (i <= 2)
	{
		write(data->fd, &value, 1);
		value = value>>8;
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
	write(data->fd, &op_tab[index].op_code, 1);
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
	write(data->fd, &arg_code, 1);
	data->ltoken = tmp;
	i = 0;
	while (data->ltoken && op_tab[index].argc > i)
	{
		res = ft_identify_arg(data);
		if (res == DIR_CODE)
			ft_write_dir(data, (op_tab[index].dir_size == 1) ? 2 : 4);
		else if (res == REG_CODE)
			ft_write_reg(data);
		else
			ft_write_ind(data);
		data->ltoken = data->ltoken->next;
		if (data->ltoken->piece[0] == ',')
			data->ltoken = data->ltoken->next;
		i++;
	}
}

void	ft_write_cmd(t_data *data, int t)
{
	if (t != 1)
		ft_skip_line(data);
	else if (!ft_strcmp((const char*)data->ltoken, NAME_CMD_STRING))
		ft_put_str(data, PROG_NAME_LENGTH);
	else if (!ft_strcmp((const char*)data->ltoken, COMMENT_CMD_STRING))
		ft_put_str(data, COMMENT_LENGTH);
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
		write(1, "here\n", 5);
		ft_exit(data, data->ltoken->line);
	}
}

void	ft_write_file(t_data *data)
{
	data->file = ft_strjoin(data->file, "or");
	if (!(data->fd = open(data->file, O_CREAT, O_RDWR))){
		write(1, "here\n", 5);
		ft_exit(data, 1);
	}
	ft_put_magic(data);
	ft_write_cmd(data, 1);
	ft_write_cmd(data, 1);
	while (data->ltoken)
	{
		ft_identify(data);
		data->ltoken = data->ltoken->next;
	}
}
