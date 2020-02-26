/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_print_stats.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melalj <melalj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 03:07:15 by melalj            #+#    #+#             */
/*   Updated: 2020/02/26 03:15:11 by melalj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

static void	visu_champions_stats_p(t_global *data, t_visu scr, int line, int i)
{
	int	col;

	col = 3;
	wmove(scr.win_stats, line, col);
	wprintw(scr.win_stats, "Champion nbr : %d",
							data->champions[i].number + 1);
	col += 24;
	wmove(scr.win_stats, line, col);
	wattron(scr.win_stats,
							COLOR_PAIR(data->champions[i].number + 1));
	wprintw(scr.win_stats, "NAME : %.30s",
							data->champions[i].byte_name);
	col += 37;
	wmove(scr.win_stats, line, col);
	if (data->champions[i].still_alive-- > 0)
		wattron(scr.win_stats, A_REVERSE);
	wprintw(scr.win_stats, "  ");
	wattroff(scr.win_stats,
							COLOR_PAIR(data->champions[i].number + 1));
	wattroff(scr.win_stats, A_REVERSE);
	col += 10;
	wmove(scr.win_stats, line, col);
	wprintw(scr.win_stats, "last cycle seen : %d",
							data->champions[i].last_live_cycle);
}

static int	visu_champions_stats(t_global *data, t_visu screen)
{
	int i;
	int line;

	i = -1;
	line = 8;
	while (++i < data->champion_count)
	{
		if (data->champions[i].validity)
		{
			visu_champions_stats_p(data, screen, line, i);
			line += 5;
		}
	}
	return (1);
}

int			visu_stats_print(t_global *data, t_visu screen)
{
	int line;
	int col;

	getmaxyx(screen.win_stats, line, col);
	line = 2;
	wmove(screen.win_stats, line, col / 2 - 14);
	wattron(screen.win_stats, A_BOLD);
	wprintw(screen.win_stats, "*^* WELCOME TO THE ARENA *^*");
	line = 4;
	col = 23;
	wmove(screen.win_stats, line, col);
	wprintw(screen.win_stats, "Cycle : %d           ", data->all_time_cycles);
	wprintw(screen.win_stats, "Cycle to DIE : %d       ", data->cycles_to_die);
	wprintw(screen.win_stats, "Cycle Delta : %d          ", CYCLE_DELTA);
	wprintw(screen.win_stats, "NBR Live : %d          ", NBR_LIVE);
	wprintw(screen.win_stats, "MAX checks : %d", MAX_CHECKS);
	visu_champions_stats(data, screen);
	wattroff(screen.win_stats, A_BOLD);
	wmove(screen.win_stats, 0, 0);
	wrefresh(screen.win_stats);
	return (1);
}
