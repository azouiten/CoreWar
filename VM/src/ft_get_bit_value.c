/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_bit_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 00:18:28 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/14 19:03:12 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarh.h"

char	ft_get_bit_value(unsigned char number, int number_bits, int position)
{
	return (((1 << number_bits) - 1) & (number >> (position - 1)));
}
