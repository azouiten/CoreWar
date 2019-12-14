/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:05:02 by ohachim           #+#    #+#             */
/*   Updated: 2019/12/13 22:18:55 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

void		ft_init_global_data(t_global *global_data)
{
	global_data->global_allocs = NULL;
	global_data->tempo_allocs = NULL;
	global_data->champions = NULL;
}

int		main(int argc, char **argv)
{
	t_global	global_data;

	ft_init_global_data(&global_data);
	ft_create_champions(&global_data, argv);
	SUCCESS;
	return (0);
}
