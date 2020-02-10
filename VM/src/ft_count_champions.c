/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_champions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 21:05:21 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/10 10:09:01 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

static int		ft_valid_champion_index(char *dash_n_arg)
{
	int			cn;

	cn = 0;
	if (!dash_n_arg)
		return (0);
	while (dash_n_arg[cn] != '\0')
	{
		if (!ft_isdigit(dash_n_arg[cn]))
			return (0);
		cn++;
	}
	if (ft_atoi(dash_n_arg) > MAX_PLAYERS)
		return (0);
	return (1);
}

int				ft_count_champions(char **argv)
{
	int			wn;
	int			champions;

	champions = 0;
	wn = 1;
	while (argv[wn])
	{
		if (ft_check_cor_extension(argv[wn]))
			champions++;
		else
		{
			if (ft_valid_champion_index(argv[wn + 1]))
				wn++;
		}
		if (!argv[wn])
			break ;
		wn++;
	}
	return (champions);
}
