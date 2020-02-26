/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melalj <melalj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 03:05:18 by melalj            #+#    #+#             */
/*   Updated: 2020/02/26 03:44:37 by melalj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

static void	visu_init_arena(t_global *data)
{
	int	i;

	i = -1;
	while (++i < 4096)
	{
		data->visu_arena[i].byte = 0;
		data->visu_arena[i].color = -1;
		data->visu_arena[i].v = 0;
		data->visu_arena[i].cursor = 0;
	}
}

static void	visu_fill_arena(t_global *data)
{
	int	i;
	int j;
	int	pos;

	i = -1;
	visu_init_arena(data);
	while (++i < data->champion_count)
	{
		if (data->champions[i].validity && (j = -1))
		{
			pos = data->champions[i].starting_point;
			while (++j < data->champions[i].hex_code_size)
			{
				data->visu_arena[pos].byte = data->champions[i].exec_code[j];
				data->visu_arena[pos].color =
										data->champions[i].number % MAX_PLAYERS;
				data->visu_arena[pos].v = 0;
				pos++;
			}
		}
	}
}

static void	add_color(void)
{
	start_color();
	init_pair(1, 1, 0);
	init_pair(2, 2, 0);
	init_pair(3, 3, 0);
	init_pair(4, 4, 0);
	init_color(1, 700, 0, 0);
	init_color(2, 0, 700, 0);
	init_color(3, 700, 700, 0);
	init_color(4, 0, 0, 700);
	init_color(9, 1000, 0, 0);
	init_color(10, 0, 1000, 0);
	init_color(11, 1000, 1000, 0);
	init_color(12, 0, 0, 1000);
	init_pair(5, 9, 0);
	init_pair(6, 10, 0);
	init_pair(7, 11, 0);
	init_pair(8, 12, 0);
}

t_visu		visu_battlegrounds(t_global *data)
{
	t_visu	screen;
	int		h;
	int		w;

	initscr();
	refresh();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	getmaxyx(stdscr, h, w);
	visu_fill_arena(data);
	screen.win_arena = newwin(68, 199, 31, 0);
	screen.win_stats = newwin(30, 199, 0, 0);
	add_color();
	wattron(screen.win_arena, A_REVERSE);
	box(screen.win_arena, ' ', ' ');
	wattroff(screen.win_arena, A_REVERSE);
	wattron(screen.win_stats, A_REVERSE);
	box(screen.win_stats, ' ', ' ');
	wattroff(screen.win_stats, A_REVERSE);
	return (screen);
}

int			end_visu(t_global *data)
{
	int	c;

	if (!data->v)
		return (0);
	while ((c = getch()) != 'q')
		endwin();
	return (1);
}
