/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cor_extension.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 23:59:56 by magoumi           #+#    #+#             */
/*   Updated: 2020/02/18 23:59:57 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

int		ft_check_cor_extension(char *potential_champion)
{
	int		last_char;

	last_char = ft_strlen(potential_champion) - 1;
	if (potential_champion[last_char] != 'r'
			|| potential_champion[last_char - 1] != 'o'
			|| potential_champion[last_char - 2] != 'c'
			|| potential_champion[last_char - 3] != '.'
			|| last_char - 4 < 0)
		return (0);
	return (1);
}
