/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_aff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 10:42:41 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/21 12:46:02 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

void			ft_print_affs(t_global global_data)
{
	while (global_data.affs)
	{
		ft_printf("AFF: %c\n", global_data.affs->value);
		global_data.affs = global_data.affs->next;
	}
}

static t_aff	*ft_add_aff_node(int aff_value, t_global *global_data)
{
	t_aff	*aff_node;

	if (!(aff_node = (t_aff*)malloc(sizeof(t_aff))))
		ft_manage_error(global_data, MALLOC_FAIL, -1, 1);
	aff_node->value = aff_value;
	aff_node->next = NULL;
	return (aff_node);
}

void			ft_execute_aff(t_process **process, t_global *global_data)
{
	int	reg;

	reg = global_data->arena[ft_euclidean_mod(((*process)->process_cursor + 2),
			MEM_SIZE)];
	if (reg < 1 || reg > REG_NUMBER)
		return ;
	if (!global_data->affs)
	{
		if (!(global_data->affs =
				ft_add_aff_node(((*process)->registries[reg - 1])
					% 256, global_data)))
			ft_manage_error(global_data, MALLOC_FAIL, -1, 1);
	}
	else
	{
		while (global_data->affs->next)
			global_data->affs = global_data->affs->next;
		if (!(global_data->affs->next =
				ft_add_aff_node(((*process)->registries[reg - 1])
					% 256, global_data)))
			ft_manage_error(global_data, MALLOC_FAIL, -1, 1);
	}
}
