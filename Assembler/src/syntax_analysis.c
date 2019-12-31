/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 18:31:08 by azouiten          #+#    #+#             */
/*   Updated: 2019/12/30 21:26:37 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_token	*ft_take_cmd(t_data *data, t_token *token, int i)
{
	int	limit;
	int	size;

	limit = (i == 1) ? PROG_NAME_LENGTH : COMMENT_LENGTH;
	token = token->next;
	size = ft_strlen(token->piece) - 2;
	if (size > limit || token->piece[0] != '"' ||
				token->piece[ft_strlen(token->piece) - 1] != '"')
	{
		ft_putstr("name or comment invalid!\n");
		ft_exit(data, 1);
	}
	return (token);
}

t_token	*ft_confirm_arg(t_data *data, t_token *token, int code, int input)
{
	if ((code & input) != input)
		ft_exit(data, 1);
	if (token->piece[0] == '%' || token->piece[0] == '-')
		token = token->next;
	return (token);
}

t_token	*ft_take_inst(t_data *data, t_token *token, int index)
{
	int	i;

	i = 0;
	while (i < op_tab[index].argc)
	{
		token = token->next;
		if (!token)
			ft_exit(data, 1);
		if (token->piece[0] == DIRECT_CHAR && token->piece[1] == '\0')
			token = ft_confirm_arg(data, token, op_tab[index].tab[i], T_DIR);
		else if (token->piece[0] == 'r')
			token = ft_confirm_arg(data, token, op_tab[index].tab[i], T_REG);
		else if (token->piece[0] == '-' && token->piece[1] == '\0')
			token = ft_confirm_arg(data, token, op_tab[index].tab[i], T_IND);
		i++;
		if (token->piece[0] == SEPARATOR_CHAR)
			token = token->next;
		else if (i != op_tab[index].argc)
			ft_exit(data, 1);
	}
	return (token);
}

t_token	*ft_verify(t_data *data, t_token *token)
{
	int	i;

	i = 0;
	if (!ft_strcmp(token->piece, NAME_CMD_STRING))
		return (ft_take_cmd(data, token, 1));
	if (!ft_strcmp(token->piece, COMMENT_CMD_STRING))
		return (ft_take_cmd(data, token, 2));
	while (op_tab[i].name)
	{
		if (!ft_strcmp(token->piece, op_tab[i].name))
			return (ft_take_inst(data, token, i));
		i++;
	}
	return (token);

}

void	ft_syntax_analysis(t_data *data)
{
	t_token	*token;

	token = data->tokens;
	while (token)
	{
		token = ft_verify(data, token);
		token = token->next;
	}
	ft_putstr("VALID!\n");
}
