/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:39:24 by azouiten          #+#    #+#             */
/*   Updated: 2020/02/01 18:51:15 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ASM_H
#define	ASM_H

#include "op.h"
#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h> //to be removed

typedef	struct		s_op
{
	char			*name;
	int				argc;
	t_arg_type		tab[3];
	int				op_code;
	int				cost;
	char			*description;
	int				p_opc;
	int				dir_size;
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
	struct	s_token	*ltoken;
	struct	s_label	*labels;
	int				fd;
	char			*file;
	int				line;
	int				dquo;
	int				n_cmd;
	int				pos;
}					t_data;

typedef	struct		s_label
{
	char			*name;
	int				pos;
	struct	s_label	*next;
}					t_label;

t_op				op_tab[17];
void				ft_syntax_analysis(t_data *data);
void				ft_exit(t_data *data, int line);
void				ft_write_file(t_data *data);
int					ft_check_inst(t_data *data);
int					ft_check_cmd(t_data *data);
int					ft_identify_arg(t_data *data);

#endif
