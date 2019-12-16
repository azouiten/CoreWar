/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:23:16 by azouiten          #+#    #+#             */
/*   Updated: 2018/10/16 21:58:24 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	*p1;

	i = 0;
	p = (unsigned char*)dst;
	p1 = (unsigned char*)src;
	while (n > i && p1[i] != (unsigned char)c)
	{
		p[i] = p1[i];
		i++;
	}
	if (p1[i] == (unsigned char)c)
	{
		p[i] = p1[i];
		return (&p[i + 1]);
	}
	return (NULL);
}
