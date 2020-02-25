/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melalj <melalj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:03:20 by melalj            #+#    #+#             */
/*   Updated: 2020/02/25 16:08:09 by melalj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include <curses.h>
# include "corewarh.h"

typedef struct	s_arena
{
	unsigned char	byte;
	int				color;
	int				v;
	int				cursor;
}				t_arena;

typedef struct s_visu
{
	WINDOW *win_arena;
	WINDOW *win_stats;
}				t_visu;

#endif
