/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 09:59:14 by azouiten          #+#    #+#             */
/*   Updated: 2018/10/16 19:55:08 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_sign(long n)
{
	int sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	return (sign);
}

static	int	ft_size(long n)
{
	int size;

	size = 0;
	if (n == 0)
		return (1);
	if (ft_sign(n) == -1)
	{
		size++;
		n *= -1;
	}
	while (n > 0)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	char	*res;
	long	n1;
	int		t;

	n1 = (long)n;
	if (!(res = (char*)malloc(sizeof(char) * (ft_size((long)n) + 1))))
		return (NULL);
	t = ft_size((long)n);
	n1 *= ft_sign((long)n);
	res[t--] = '\0';
	if (n1 == 0)
		res[0] = '0';
	if (ft_sign(n) == -1)
		res[0] = '-';
	while (n1 > 0)
	{
		res[t--] = (n1 % 10) + '0';
		n1 /= 10;
	}
	return (res);
}
