/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_bit_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 00:18:28 by ohachim           #+#    #+#             */
/*   Updated: 2020/01/16 15:52:51 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_get_bit_value(int number, int number_bits, int position)
{
	return (((1 << number_bits) - 1) & (number >> (position - 1)));
}
