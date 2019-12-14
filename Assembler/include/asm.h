/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:39:24 by azouiten          #+#    #+#             */
/*   Updated: 2019/12/13 18:50:12 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ASSEMBLER_H
#define	ASSEMBLER_H

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
}					t_data;

#endif
