/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_hq.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:59:03 by ohachim           #+#    #+#             */
/*   Updated: 2020/01/23 06:54:08 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

void	ft_execute_hq(t_process **process, t_global *global_data)
{
	ft_printf("hwlloooooo %d\n", (*process)->current_op);
	if ((*process)->current_op == LIVE)
		ft_execute_live(process, global_data);
	else if ((*process)->current_op == LOAD)
		ft_execute_load(process, global_data);
}
