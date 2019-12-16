/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:39:24 by azouiten          #+#    #+#             */
/*   Updated: 2019/12/16 19:38:43 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ASM_H
#define	ASM_H

#include "libft.h"
#include <unistd.h>
#include <fcntl.h>


typedef	struct		s_file
{
	char			*name;
	int				fd;
	struct	s_file	*next;
}					t_file;

typedef	struct		s_token
{
	char			*piece;
	struct	s_token	*last;
	struct	s_token	*next;
}					t_token;

typedef	struct		s_data
{
	struct	s_file	*files;
	struct	s_token	*tokens;
	int				curr_pos;
}					t_data;

typedef	struct		s_label
{
	char			*name;
	int				pos;
	struct	s_label	*next;
}

void				ft_syntax_analysis(t_data *data);

#endif
