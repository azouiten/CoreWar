/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_print_arena.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melalj <melalj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:15:51 by melalj            #+#    #+#             */
/*   Updated: 2020/02/26 03:18:58 by melalj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

static int	kids_mode_print(t_global *data, t_visu screen, int i)
{
	if (data->visu_arena[i].cursor && !(data->visu_arena[i].cursor = 0))
		wprintw(screen.win_arena, "Pc");
	else
	{
		wattron(screen.win_arena, A_REVERSE);
		wprintw(screen.win_arena, "  ", data->visu_arena[i].byte);
		wattroff(screen.win_arena, A_REVERSE);
	}
	wprintw(screen.win_arena, " ");
	return (1);
}

static int	visu_kids_mode_baner(t_visu screen, int k)
{
	wattron(screen.win_arena, A_REVERSE);
	box(screen.win_arena, ' ', ' ');
	wattroff(screen.win_arena, A_REVERSE);
	if (k)
	{
		wattron(screen.win_arena, A_BOLD);
		wmove(screen.win_arena, 0, 92);
		wattron(screen.win_arena, COLOR_PAIR(1));
		wprintw(screen.win_arena, "  KI");
		wattroff(screen.win_arena, COLOR_PAIR(1));
		wmove(screen.win_arena, 0, 96);
		wattron(screen.win_arena, COLOR_PAIR(2));
		wprintw(screen.win_arena, "DS ");
		wattroff(screen.win_arena, COLOR_PAIR(2));
		wattron(screen.win_arena, COLOR_PAIR(3));
		wmove(screen.win_arena, 0, 99);
		wprintw(screen.win_arena, "MO");
		wattroff(screen.win_arena, COLOR_PAIR(3));
		wmove(screen.win_arena, 0, 101);
		wattron(screen.win_arena, COLOR_PAIR(4));
		wprintw(screen.win_arena, "DE  ");
		wattroff(screen.win_arena, COLOR_PAIR(4));
		wattroff(screen.win_arena, A_BOLD);
	}
	return (1);
}

static int	visu_normal_mode_print(t_global *data, t_visu screen, int i)
{
	if (data->visu_arena[i].cursor && !(data->visu_arena[i].cursor = 0))
		wattron(screen.win_arena, A_REVERSE);
	wprintw(screen.win_arena, "%.2x", data->visu_arena[i].byte);
	wattroff(screen.win_arena, A_REVERSE);
	wattroff(screen.win_arena, COLOR_PAIR(2));
	wprintw(screen.win_arena, " ");
	return (1);
}

static void	visu_cursor_print(t_global *data, t_visu screen, int k)
{
	int			i;
	t_process	*curs;

	curs = data->processes;
	i = 0;
	visu_kids_mode_baner(screen, k);
	while (curs)
	{
		if (curs->alive && ++i)
			data->visu_arena[curs->process_cursor].cursor = 1;
		curs = curs->next;
	}
	wattron(screen.win_stats, A_BOLD);
	wmove(screen.win_stats, 4, 150);
	wprintw(screen.win_stats, "Total processes alive : %d", i);
	wattroff(screen.win_stats, A_BOLD);
}

int			visu_arena_print(t_global *data, t_visu screen, int k)
{
	int i;
	int line;

	visu_cursor_print(data, screen, k);
	line = 1;
	i = -1;
	while (++i < 4096)
	{
		if (i % 64 == 0 && ++line)
			wmove(screen.win_arena, line, 4);
		if (data->visu_arena[i].color != -1)
		{
			if (data->visu_arena[i].v && data->visu_arena[i].v--)
				wattron(screen.win_arena,
					COLOR_PAIR(data->visu_arena[i].color + 1 + 4));
			else
				wattron(screen.win_arena,
					COLOR_PAIR(data->visu_arena[i].color + 1));
		}
		((k) ? kids_mode_print(data, screen, i)
					: visu_normal_mode_print(data, screen, i));
		wattroff(screen.win_arena, COLOR_PAIR(2));
	}
	wrefresh(screen.win_arena);
	return (1);
}
