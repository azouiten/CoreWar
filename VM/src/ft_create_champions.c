/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_champions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 21:57:29 by magoumi           #+#    #+#             */
/*   Updated: 2020/02/24 20:05:49 by melalj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

static int	ft_champion_count(char **argv)
{
	int	argn;
	int	champ_num;

	champ_num = 0;
	argn = 1;
	while (argv[argn])
	{
		if (ft_check_cor_extension(argv[argn]))
			champ_num++;
		argn++;
	}
	return (champ_num);
}

static void	ft_init_champions(t_global *data)
{
	int	i;

	i = 0;
	while (i < data->champion_count)
	{
		data->champions[i].name = NULL;
		data->champions[i].comment = NULL;
		data->champions[i].byte_name = NULL;
		data->champions[i].exec_code = NULL;
		data->champions[i].validity = 1;
		data->champions[i].hex_code_size = 0;
		data->champions[i].number = i;
		data->champions[i].argn = -1;
		data->champions[i].fd = -1;
		data->champions[i].starting_point = -1;
		data->champions[i].last_live_cycle = 0;
		data->champions[i].still_alive = 0;
		i++;
	}
}

void		ft_create_champions(t_global *data, char **argv)
{
	if (!(data->champion_count = ft_champion_count(argv)))
		ft_manage_error(data, ZERO_CHAMPION, -1, 1);
	if (data->champion_count > MAX_PLAYERS)
		ft_manage_error(data, TOO_MANY_PLAYERS, -1, 1);
	if (!(data->champions = (t_champion*)malloc(data->champion_count
			* sizeof(t_champion))))
		ft_manage_error(data, MALLOC_FAIL, -1, 1);
	ft_init_champions(data);
}
