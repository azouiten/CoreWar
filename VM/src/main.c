/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:05:02 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/06 22:16:55 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

static void	ft_declare_champions(t_global global_data)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	ft_printf("Introducing contestants...\n");
	while (i < global_data.champion_count)
	{
		if (global_data.champions[i].validity)
		{
			ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", j,
					global_data.champions[i].hex_code_size,
					global_data.champions[i].byte_name,
					global_data.champions[i].comment);
			j++;
		}
		i++;
	}
}

static void	ft_init_global_data(t_global *global_data)
{
	global_data->champions = NULL;
	global_data->all_time_cycles = 0;
	global_data->error_buf = NULL;
	global_data->champion_count = 0;
	global_data->valid_champions = 0;
	global_data->processes = NULL;
	global_data->number_lives_declared = 0;
	global_data->cycles_to_die = CYCLE_TO_DIE;
	global_data->number_of_checks = 0;
}

int			main(int argc, char **argv)
{
	t_global	global_data;
	int			i;

	i = 0;
	ft_init_global_data(&global_data);
	ft_create_champions(&global_data, argv);
	ft_check_magic_headers(&global_data, 0, 0);
	ft_gather_byte_code(&global_data);
	ft_declare_champions(global_data);
	ft_prepare_arena(&global_data);
	ft_printf("Contestant %d, \"%s\", has won !\n",
	global_data.last_live_player.number + 1,
	global_data.last_live_player.byte_name);
	ft_free_data(&global_data);
}
