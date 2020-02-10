/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cor_extension.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 23:26:11 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/10 05:12:10 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

int			ft_check_cor_extension(char *potential_champion)
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
