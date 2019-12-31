/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:39:24 by azouiten          #+#    #+#             */
/*   Updated: 2019/12/30 21:45:46 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ASM_H
#define	ASM_H

#include "op.h"
#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h> //hied had l 9lawi

typedef	struct		s_op
{
	char			*name;
	int				argc;
	t_arg_type		tab[3];
	int				op_code;
	int				cost;
	char			*description;
	int				NA;
	int				NA0;
}					t_op;

typedef	struct		s_file
{
	char			*name;
	int				fd;
	struct	s_file	*next;
}					t_file;

typedef	struct		s_token
{
	char			*piece;
	int				line;
	struct	s_token	*last;
	struct	s_token	*next;
}					t_token;

typedef	struct		s_data
{
	struct	s_file	*files;
	struct	s_token	*tokens;
	int				curr_pos;
	int				dquo;
}					t_data;

typedef	struct		s_label
{
	char			*name;
	int				pos;
	struct	s_label	*next;
}					t_label;

t_op				op_tab[17];
void				ft_syntax_analysis(t_data *data);
void				ft_exit(t_data *data, int status);

#endif
