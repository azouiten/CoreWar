/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melalj <melalj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:03:20 by melalj            #+#    #+#             */
/*   Updated: 2020/02/24 16:55:23 by melalj           ###   ########.fr       */
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

#endif
