/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 20:51:05 by azouiten          #+#    #+#             */
/*   Updated: 2018/10/16 19:13:23 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	long	i;
	long	sign;
	long	res;

	res = 0;
	sign = 1;
	i = 0;
	while (s[i] == '\t' || s[i] == ' ' || s[i] == '\r'
			|| s[i] == '\n' || s[i] == '\f' || s[i] == '\v')
		i++;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = (res + s[i] - '0') * 10;
		i++;
	}
	res = (res / 10) * sign;
	return ((int)res);
}
