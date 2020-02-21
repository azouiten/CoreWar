/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_champions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 21:57:29 by magoumi           #+#    #+#             */
/*   Updated: 2020/02/19 00:04:19 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

int		ft_champion_count(char **argv)
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

void	ft_init_champions(t_global *data)
{
	size_t	i;

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
		i++;
	}
}

/*
**	add protection to the next function
*/

void	ft_create_champions(t_global *data, char **argv)
{
	if (!(data->champion_count = ft_champion_count(argv)))
		return ;
	if (data->champion_count > MAX_PLAYERS)
		return ;
	if (!(data->champions = (t_champion*)malloc(data->champion_count
			* sizeof(t_champion))))
		return ;
	ft_init_champions(data);
}
