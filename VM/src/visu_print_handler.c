/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_print_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melalj <melalj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 03:12:35 by melalj            #+#    #+#             */
/*   Updated: 2020/02/26 03:56:39 by melalj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

static void	visu_delay(t_visu screen, int delay)
{
	wmove(screen.win_stats, 29, 92);
	wattron(screen.win_stats, A_BOLD);
	wprintw(screen.win_stats, " Delay : %.3d ", delay);
	wattroff(screen.win_stats, A_BOLD);
	usleep(1000 * delay);
}

int			visu_key_handling(t_global *data, t_visu screen)
{
	int			key;
	static int	delay = 20;
	static int	k;

	if (!data->v)
		return (0);
	nodelay(stdscr, TRUE);
	if ((key = getch()) == 'q')
	{
		endwin();
		exit(0);
	}
	else if (key == 'p')
		while ((key = getch()) != 'p')
			;
	else if (key == 'd' && delay + 10 <= 120)
		delay += 10;
	else if (key == 'a' && delay - 10 >= 0)
		delay -= 10;
	else if (key == 'k')
		k = k ? 0 : 1;
	visu_delay(screen, delay);
	visu_arena_print(data, screen, k);
	visu_stats_print(data, screen);
	return (1);
}
