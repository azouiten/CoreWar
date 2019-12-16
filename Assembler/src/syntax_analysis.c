/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 18:31:08 by azouiten          #+#    #+#             */
/*   Updated: 2019/12/16 20:30:47 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_identify(t_token *token)
{
	if (!ft_strcmp(token->piece, NAME_CMD_STRING))
		return (1);
	if (!ft_strcmp(token->piece, COMMENT_CMD_STRING))
		return (2);
	if (!ft_strcmp(token->piece, "live"))
		return (3);
	if (!ft_strcmp(token->piece, "ld"))
		return (4);
	if (!ft_strcmp(token->piece, "st"))
		return (5);
	if (!ft_strcmp(token->piece, "add"))
		return (6);
	if (!ft_strcmp(token->piece, "sub"))
		return (7);
	if (!ft_strcmp(token->piece, "and"))
		return (8);
	if (!ft_strcmp(token->piece, "or"))
		return (9);
	if (!ft_strcmp(token->piece, "xor"))
		return (10);
	if (!ft_strcmp(token->piece, "zjmp"))
		return (11);
	if (!ft_strcmp(token->piece, "ldi"))
		return (12);
	if (!ft_strcmp(token->piece, "sti"))
		return (13);
	if (!ft_strcmp(token->piece, "fork"))
		return (14);
	if (!ft_strcmp(token->piece, "lld"))
		return (15);
	if (!ft_strcmp(token->piece, "lldi"))
		return (16);
	if (!ft_strcmp(token->piece, "lfork"))
		return (17);
	if (!ft_strcmp(token->piece, "aff"))
		return (18);
	if (ft_is_cmd(token->piece))
		return (19);
	return (0);
}

void	ft_syntax_analysis(t_data *data)
{
	t_token	*token;

	token = data->token;
	while (token)
	{
		if (ft_identify(token) == 1)
		token = token->next;
	}
}
