/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_cpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 09:39:57 by ohachim           #+#    #+#             */
/*   Updated: 2020/01/25 09:40:41 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

void     ft_arena_cpy(t_global *global_data, int cpy_to, int to_cpy)
{
        t_hexa  store_hexa;
        int     cn;

        cn = 3;
        store_hexa.value = to_cpy;
        while (cn >= 0)
        {
                global_data->arena[cpy_to] = store_hexa.buf[cn];
                cpy_to++;
                cn--;
        }
        ft_printf("\n");
}
