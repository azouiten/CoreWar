/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 11:43:34 by azouiten          #+#    #+#             */
/*   Updated: 2018/10/09 02:55:28 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*p;
	char	*p1;

	i = 0;
	p = (char*)dst;
	p1 = (char*)src;
	while (n > i)
	{
		p[i] = p1[i];
		i++;
	}
	return (dst);
}
