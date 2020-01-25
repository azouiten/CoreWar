/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_argument_dir_long.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 03:46:48 by ohachim           #+#    #+#             */
/*   Updated: 2020/01/25 03:47:15 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

int      ft_extract_argument_dir_long(t_global *global_data, t_process **process, int byte_distance)
{
        t_hexa          load_union;

        load_union.buf[3] = global_data->arena[(*process)->process_cursor + byte_distance];
        load_union.buf[2] = global_data->arena[(*process)->process_cursor + byte_distance + 1];
        load_union.buf[1] = global_data->arena[(*process)->process_cursor + byte_distance + 2];
        load_union.buf[0] = global_data->arena[(*process)->process_cursor + byte_distance + 3];
        return (load_union.value);
}
