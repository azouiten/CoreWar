/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 13:39:18 by azouiten          #+#    #+#             */
/*   Updated: 2019/12/31 03:26:47 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_exit(t_data *data, int status)
{
	(void)data;
	//	ft_free_data(data);
	exit(status);
}

void	ft_list_tokens(t_data *data)
{
	while (data->tokens)
	{
		printf("{%s}\n", data->tokens->piece);
		data->tokens = data->tokens->next;
	}
}

int		ft_isplit(char c)
{
	return (c == SEPARATOR_CHAR || c == LABEL_CHAR || c == DIRECT_CHAR);
}

int		ft_istring(t_data *data, char c)
{
	return ((c != SEPARATOR_CHAR && c != '\t' && c != ' ' && c != LABEL_CHAR
			&& c != DIRECT_CHAR) || data->dquo);
}

t_token	*token_neo_genesis(t_data *data)
{
	t_token	*token;

	if (!(token = (t_token*)malloc(sizeof(t_token))))
		ft_exit(data, 1);
	token->piece = NULL;
	return (token);
}

void	ft_add_token(t_data *data, t_token *token)
{
	if (data->tokens == NULL)
	{
		data->tokens = token;
		data->tokens->last = token;
	}
	else
	{
		data->tokens->last->next = token;
		data->tokens->last = token;
		data->tokens->last->last = NULL;
	}
}

int		ft_take_token(t_data *data, char *str)
{
	int		i;
	int		j;
	t_token	*token;

	i = 0;
	j = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	j = i;
	if (str[i] == '#')
		return (i);
	while (str[i] && ft_istring(data, str[i]))
	{
		if (str[i] == '"')
			data->dquo = (data->dquo == 1) ? 0 : 1;
		if (str[i] == '#')
			break ;
		i++;
	}
	if (i != j)
	{
		token = token_neo_genesis(data);
		token->piece = ft_strsub(str, j, i - j);
		ft_add_token(data, token);
		return (i);
	}
	if (str[i] && ft_isplit(str[i]))
		i++;
	token = token_neo_genesis(data);
	token->piece = ft_strsub(str, j, i - j);
	ft_add_token(data, token);
	return (i);
}

void	ft_add_spliter(t_data *data)
{
	t_token	*token;

	token = token_neo_genesis(data);
	token->piece = ft_strdup("\n");
	ft_add_token(data, token);
}

int		ft_rest_string(t_data *data, char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '"')
		i++;
	data->tokens->last->piece = ft_strjoin(data->tokens->last->piece,
			ft_strsub(str, 0, (str[i] == '"') ? i + 1 : i));
	if (str[i] == '"')
	{
		i++;
		data->dquo = 0;
	}
	return (i);
}

void	ft_lexical_analysis(t_data *data, char *str)
{
	int	i;

	i = 0;
	if (data->dquo == 1)
		i += ft_rest_string(data, str);
	while (str[i])
	{
		if (str[i] == ';' || str[i] == COMMENT_CHAR)// ignores the comments!
			break ;
		i += ft_take_token(data, str + i);
	}
	if (str[0] != '\0' && data->dquo != 1)
		ft_add_spliter(data);
	ft_strdel(&str);
}

void	ft_parse(t_data *data, char *str)
{
	int	fd;

	if(!(fd = open(str, O_RDONLY)))
		ft_exit(data, 1);
	while ((str = get_next_line(fd)))
		ft_lexical_analysis(data, str);
	if (!data->tokens)
		ft_exit(data, 1);
	ft_syntax_analysis(data);
}

t_data	*data_neo_genesis(void)
{
	t_data	*data;

	if (!(data = (t_data*)malloc(sizeof(t_data))))
		ft_exit(NULL, 1);
	data->files = NULL;
	data->tokens = NULL;
	data->dquo = 0;
	return (data);
}

static	void	ft_check_argument(int argc)
{
	if (argc == 1)
	{
		write(2, "NO FILE IS PROVIDED.\n", 21);
		exit(1);
	}
}

int				main(int argc, char **argv)
{
	t_data	*data;

	data = data_neo_genesis();
	ft_check_argument(argc);
	ft_parse(data, argv[1]);
	ft_list_tokens(data);
	return (0);
}
