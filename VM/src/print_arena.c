/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arena.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melalj <melalj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:15:51 by melalj            #+#    #+#             */
/*   Updated: 2020/02/25 22:08:42 by melalj           ###   ########.fr       */
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

int	kids_mode_print(t_global *data, t_visu screen, int i){

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

int	visu_kids_mode_baner(t_visu screen, int k)
{
	wattron(screen.win_arena, A_REVERSE);
	box(screen.win_arena, ' ', ' ');
	wattroff(screen.win_arena, A_REVERSE);
	if (k)
	{
		wattron(screen.win_arena, A_BOLD);
		wmove(screen.win_arena, 0, 92);
		wattron(screen.win_arena, COLOR_PAIR(1));
		wprintw(screen.win_arena, " KI");
		wattroff(screen.win_arena, COLOR_PAIR(1));
		wmove(screen.win_arena, 0, 95);
		wattron(screen.win_arena, COLOR_PAIR(2));
		wprintw(screen.win_arena, "DS ");
		wattroff(screen.win_arena, COLOR_PAIR(2));
		wattron(screen.win_arena, COLOR_PAIR(3));
		wmove(screen.win_arena, 0, 98);
		wprintw(screen.win_arena, "MO");
		wattroff(screen.win_arena, COLOR_PAIR(3));
		wmove(screen.win_arena, 0, 100);
		wattron(screen.win_arena, COLOR_PAIR(4));
		wprintw(screen.win_arena, "DE ");
		wattroff(screen.win_arena, COLOR_PAIR(4));
		wattroff(screen.win_arena, A_BOLD);
	}
	return (1);
}

int	visu_arena_print(t_global *data, t_visu screen, int k)
{
	int i;
	int line;
	t_process *curs;

	curs = data->processes;
	line = 1;
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
	i = -1;
	while (++i < 4096)
	{
		if (i % 64 == 0 && ++line)
			wmove(screen.win_arena, line, 4);
		if (data->visu_arena[i].color != -1)
		{
			if(data->visu_arena[i].v && data->visu_arena[i].v--)
				wattron(screen.win_arena, COLOR_PAIR(data->visu_arena[i].color + 1 + 4));
			else
				wattron(screen.win_arena, COLOR_PAIR(data->visu_arena[i].color + 1));
		}
		if (!k)
		{
			if (data->visu_arena[i].cursor && !(data->visu_arena[i].cursor = 0))
				wattron(screen.win_arena, A_REVERSE);
			wprintw(screen.win_arena, "%.2x", data->visu_arena[i].byte);
			wattroff(screen.win_arena, A_REVERSE);
			wattroff(screen.win_arena, COLOR_PAIR(2));
			wprintw(screen.win_arena, " ");
		}
		else
			kids_mode_print(data, screen, i);
		wattroff(screen.win_arena, A_REVERSE);
		wattroff(screen.win_arena, COLOR_PAIR(2));
	}
	wrefresh(screen.win_arena);
	return (1);
}

int	visu_champions_stats(t_global *data, t_visu screen)
{
	int i;
	int line;
	int col;

	i = -1;
	line = 8;
	while (++i < data->champion_count)
	{
		col = 3;
		wmove(screen.win_stats, line, col);
		if (data->champions[i].validity)
		{
			wprintw(screen.win_stats, "Champion nbr : %d", data->champions[i].number + 1);
			col += 24;
			wmove(screen.win_stats, line, col);
			wattron(screen.win_stats, COLOR_PAIR(data->champions[i].number + 1));
			wprintw(screen.win_stats, "NAME : %.30s", data->champions[i].byte_name);
			col += 37;
			wmove(screen.win_stats, line, col);
			if (data->champions[i].still_alive-- > 0)
			{
				wattron(screen.win_stats, A_REVERSE);
			}
			wprintw(screen.win_stats, "  ");
			wattroff(screen.win_stats, COLOR_PAIR(data->champions[i].number + 1));
			wattroff(screen.win_stats, A_REVERSE);
			col += 10;
			wmove(screen.win_stats, line, col);
			wprintw(screen.win_stats, "last cycle seen : %d", data->champions[i].last_live_cycle);
			line += 5;
		}
	}
	return (1);
}

int	visu_stats_print(t_global *data, t_visu screen)
{
	int line;
	int col;
	(void)data;
	getmaxyx(screen.win_stats, line, col);
	line = 2;
	wmove(screen.win_stats, line, col / 2 - 14);
	wattron(screen.win_stats, A_BOLD);
	wprintw(screen.win_stats, "*^* WELCOME TO THE ARENA *^*");
	line = 4;
	col = 23;
	wmove(screen.win_stats, line, col);
	wprintw(screen.win_stats, "Cycle : %d          Cycle to DIE : %d           Cycle Delta : %d          NBR Live : %d          MAX checks : %d", data->all_time_cycles, data->cycles_to_die, CYCLE_DELTA, NBR_LIVE, MAX_CHECKS);
	visu_champions_stats(data, screen);
	wattroff(screen.win_stats, A_BOLD);
	wmove(screen.win_stats, 0, 0);
	wrefresh(screen.win_stats);
	return (1);
}

int	visu_key_handling(t_global *data, t_visu screen)
{
	int key;
	static int speed = 20;
	static int k;

	nodelay(stdscr, TRUE);
	key = getch();
	if (key == 'q')
	{
		endwin();
		exit(0);
	}
	else if (key == 'p')
		while ((key = getch()) != 'p')
			;
	else if (key == 'd' && speed + 10 <= 120)
		speed+=10;
	else if(key == 'a' && speed - 10 >= 0)
		speed-=10;
	else if (key == 'k')
		k = k ? 0 : 1;
	wmove(screen.win_stats, 29, 92);
	wattron(screen.win_stats, A_BOLD);
	wprintw(screen.win_stats, " Delay : %.3d ", speed);
	wattroff(screen.win_stats, A_BOLD);
	usleep(1000 * speed);
	visu_arena_print(data, screen, k);
	visu_stats_print(data, screen);
	return (1);
}

void	add_color()
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

t_visu visu_battlegrounds(t_global *data)
{
	t_visu	screen;
	int		h;
	int		w;

	(void)data;
	initscr();
	refresh();
	cbreak();
	noecho();
	//keypad(stdscr, TRUE);
	getmaxyx(stdscr, h , w);
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
	return(screen);
}

int	end_visu()
{
	int	c;

	while ((c = getch()) != 'q')
		endwin();
	return (1);
}
