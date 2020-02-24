/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arena.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melalj <melalj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:15:51 by melalj            #+#    #+#             */
/*   Updated: 2020/02/24 17:27:01 by melalj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

void	visu_fill_arena(t_global *global_data)
{
	int	i;
	int j;
	int	pos;

	i = -1;
	while (++i < 4096)
	{
		global_data->visu_arena[i].byte = 0;
		global_data->visu_arena[i].color = -1;
		global_data->visu_arena[i].v = 0;
		global_data->visu_arena[i].cursor = 0;
	}
	i = -1;
	while (++i < global_data->champion_count)
	{
		if (global_data->champions[i].validity)
		{
			j = -1;
			pos = global_data->champions[i].starting_point;
			while (++j < global_data->champions[i].hex_code_size)
			{
				global_data->visu_arena[pos].byte = global_data->champions[i].exec_code[j];
				global_data->visu_arena[pos].color = global_data->champions[i].number % MAX_PLAYERS;
				global_data->visu_arena[pos].v = 0;
				pos++;
			}
		}
	}
}

int	visu_arena_print(t_global *data, WINDOW *win)
{
	int i;
	int line;
	t_process *curs;
	
	curs = data->processes;
	line = 1;
	i = -1;
	(void)win;
	while (curs)
	{
		data->visu_arena[curs->process_cursor].cursor = 1;
		curs = curs->next;
	}
	while (++i < 4096)
	{
		if (i % 64 == 0 && ++line)
			wmove(win, line, 4);
		if (data->visu_arena[i].color != -1)
			wattron(win, COLOR_PAIR(data->visu_arena[i].color + 1));
		if (data->visu_arena[i].cursor && !(data->visu_arena[i].cursor = 0))
			wattron(win, A_REVERSE);
		wprintw(win, "%.2x", data->visu_arena[i].byte);
			wattroff(win, A_REVERSE);
			wattroff(win, COLOR_PAIR(2));
		wprintw(win, " ");
	}
	wrefresh(win);
	return (1);
}

void	add_color()
{
	start_color();
	init_pair(1, 1, 0);
	init_pair(2, 2, 0);
	init_pair(3, 3, 0);
	init_pair(4, 4, 0);
	init_color(9, 1000, 0, 0);
	init_color(10, 0, 1000, 0);
	init_color(11, 1000, 1000, 0);
	init_color(12, 0, 0, 1000);
	init_pair(5, 9, 0);
	init_pair(6, 10, 0);
	init_pair(7, 11, 0);
	init_pair(8, 12, 0);
}

WINDOW *visu_battlegrounds(t_global *data)
{
	WINDOW	*win;
	int		h;
	int		w;
	
	(void)data;
	win = NULL;
	initscr();
	refresh();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	getmaxyx(stdscr, h , w);
	visu_fill_arena(data);
	win = newwin(68, 199, 0, 0);
	wattron(win, A_REVERSE);
	add_color();
	box(win, ' ', ' ');
	wattroff(win, A_REVERSE);
	return(win);
}

int	end_visu()
{
	getch();
	endwin();
	return (1);
}
