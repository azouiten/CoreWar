/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 18:31:08 by azouiten          #+#    #+#             */
/*   Updated: 2020/01/16 20:38:37 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"


int		ft_check_cmd(t_data *data)
{
	if (!ft_strcmp(data->ltoken->piece, NAME_CMD_STRING))
	{
		data->n_cmd++;
		return (1);
	}
	if (!ft_strcmp(data->ltoken->piece, COMMENT_CMD_STRING))
	{
		data->n_cmd++;
		return (2);
	}
	if (!ft_strcmp(data->ltoken->piece, ".extend")) //need to cover all cmds
		return (3);
	return (0);
}

int		ft_check_label(t_data *data)
{
	int	i;

	i = 0;
	if (data->ltoken->piece[ft_strlen(data->ltoken->piece) - 1] != LABEL_CHAR)
		return (0);
	while (data->ltoken->piece[i] != LABEL_CHAR)
	{
		if (!ft_strchr(LABEL_CHARS, data->ltoken->piece[i]))
			return (0);
		i++;
	}
	if (data->ltoken->piece[++i] != '\0')
		return (0);
	return (1);
}

int		ft_check_inst(t_data *data)
{
	int i;

	i = 0;
	while (op_tab[i].name)
	{
		if (!ft_strcmp(op_tab[i].name, data->ltoken->piece))
			return (i);
		i++;
	}
	return (-1);
}

void	ft_take_cmd(t_data *data, int t)
{
	if (t > 3)
		data->n_cmd++;
	data->ltoken = data->ltoken->next;
	if (data->ltoken->piece[0] != '"' ||
		data->ltoken->piece[ft_strlen(data->ltoken->piece) - 1] != '"')
		ft_exit(data, data->ltoken->line);
	data->ltoken = data->ltoken->next;
	if (!data->ltoken || data->ltoken->piece[0] != '\n')
		ft_exit(data, data->ltoken->line);
}

void	ft_take_label(t_data *data)
{
	t_label	*label;

	if (!(label = (t_label*)malloc(sizeof(t_label))))
			ft_exit(data, data->ltoken->line);
	label->name = ft_strsub(data->ltoken->piece, 0, ft_strlen(data->ltoken->piece - 1));
	label->pos = data->pos;
	label->next = data->labels;
	data->labels = label;
}

int		ft_is_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

int		ft_is_label(char *str)
{
	int i;

	i = 0;
	printf("label{%s}\n", str);
	if (str[i] != LABEL_CHAR)
		return (0);
	i++;
	while (str[i])
	{
		if (!ft_strchr(LABEL_CHARS, str[i]))
			return (0);
		i++;
	}
	return (1);
}

int		ft_identify_arg(t_data *data)
{
	if (data->ltoken->piece[0] == DIRECT_CHAR && (ft_is_num(data->ltoken->next->piece) ||
				ft_is_label(data->ltoken->next->piece))){
		printf("dir\n");
		data->ltoken = data->ltoken->next;
		return (DIR_CODE);}
	else if (data->ltoken->piece[0] == 'r' && ft_is_num(data->ltoken->piece + 1)
			&& (ft_atoi(data->ltoken->piece + 1) < REG_NUMBER)){ // is it < or <=, needs a quick check.
		printf("reg\n");
		return (REG_CODE);}
	else if (ft_is_num(data->ltoken->piece) || ft_is_label(data->ltoken->piece)){
		printf("ind\n");
		return (IND_CODE);}
	else{
		printf("out we go\n");
		ft_exit(data, data->ltoken->line);}
	return (0);
}

void	ft_get_arg(t_data *data, int arg)
{
	int	code;

	data->ltoken = data->ltoken->next;
	if (!data->ltoken)
		ft_exit(data, data->ltoken->line);
	code = ft_identify_arg(data);
	write(1, "arg\n", 4);
	if ((code & arg) != code)
		ft_exit(data, data->ltoken->line);
}

void	ft_get_sep(t_data *data)
{
	data->ltoken = data->ltoken->next;
	if (data->ltoken->piece[0] != ',')
		ft_exit(data, data->ltoken->line);
}

void	ft_take_inst(t_data *data, int t)
{
	int	i;

	i = 0;
	while (op_tab[t].argc > i)
	{
		ft_get_arg(data, op_tab[t].tab[i]);
		i++;
		if (i != op_tab[t].argc)
			ft_get_sep(data);
		printf("----------\n");
	}
	printf("argnum = %i\n", i);
	printf("+++++++++++++++++++++++++++\n");
}

void	ft_verify(t_data *data)
{
	int t;

	t = 0;
	if ((t = ft_check_cmd(data))){
		write (1, "in cmd\n", 7);
		ft_take_cmd(data, t);}
	else if (ft_check_label(data)){
		write (1, "in label\n", 9);
		ft_take_label(data);}
	else if ((t = ft_check_inst(data)) != -1){
		write (1, "in inst\n", 8);
		ft_take_inst(data, t);}
	else if (data->ltoken->piece[0] != '\0' && data->ltoken->piece[0] != '\n')
	{
		write (1, "in out\n", 7);
		ft_exit(data, data->ltoken->line);
	}
}

void	ft_syntax_analysis(t_data *data)
{
	data->ltoken = data->tokens;
	while (data->ltoken)
	{
		while (data->ltoken && data->ltoken->piece[0] == '\n')
			data->ltoken = data->ltoken->next;
		if (!data->ltoken)
			break;
		ft_verify(data);
		data->ltoken = data->ltoken->next;
	}
	if (data->n_cmd != 2)
		ft_exit(data, data->ltoken->line);
	ft_putstr("VALID!\n");
}
