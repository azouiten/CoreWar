/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_aff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 10:42:41 by ohachim           #+#    #+#             */
/*   Updated: 2020/01/30 09:47:02 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

void	ft_execute_aff(t_process **process, t_global *global_data)
{
	int	reg;

	reg = global_data->arena[ft_euclidean_mod(((*process)->process_cursor + 2), MEM_SIZE)];
	ft_printf("%c\n", (char)((*process)->registries[reg - 1]));
}
	