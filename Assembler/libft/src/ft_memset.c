/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 10:02:16 by azouiten          #+#    #+#             */
/*   Updated: 2018/10/09 02:54:16 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*q;
	size_t			i;

	i = 0;
	q = b;
	while (len > i)
	{
		q[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
