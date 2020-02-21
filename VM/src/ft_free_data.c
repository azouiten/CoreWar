/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 22:15:20 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/21 12:36:53 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

static void		ft_free_affs(t_global *global_data)
{
	t_aff	*temp_aff;

	while (global_data->affs)
	{
		temp_aff = global_data->affs->next;
		ft_memdel((void**)&(global_data->affs));
		global_data->affs = temp_aff;
	}
}

static void		ft_free_processes(t_global *global_data)
{
	t_process	*temp_process;
	t_process	*temp_process_next;

	temp_process = global_data->processes;
	while (temp_process)
	{
		temp_process_next = temp_process->next;
		ft_memdel((void**)&temp_process);
		temp_process = temp_process_next;
	}
}

static void		ft_free_champion_content(t_global *global_data, int i)
{
	if (global_data->champions[i].fd >= 0)
		close(global_data->champions[i].fd);
	if (global_data->champions[i].byte_name)
	{
		free(global_data->champions[i].byte_name);
		global_data->champions[i].byte_name = 0;
	}
	if (global_data->champions[i].comment)
	{
		free(global_data->champions[i].comment);
		global_data->champions[i].comment = 0;
	}
	if (global_data->champions[i].exec_code)
	{
		free(global_data->champions[i].exec_code);
		global_data->champions[i].exec_code = 0;
	}
}

void			ft_free_data(t_global *global_data)
{
	int	i;

	i = 0;
	if (global_data->champions)
	{
		while (i < global_data->champion_count)
		{
			ft_free_champion_content(global_data, i);
			i++;
		}
		ft_memdel((void**)&global_data->champions);
	}
	ft_memdel((void**)&global_data->error_buf);
	ft_memdel((void**)&global_data->arena);
	ft_memdel((void**)&global_data->arena_dump);
	ft_free_processes(global_data);
	if (global_data->affs)
		ft_free_affs(global_data);
}
