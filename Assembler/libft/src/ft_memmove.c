/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 19:38:01 by azouiten          #+#    #+#             */
/*   Updated: 2018/10/16 10:59:51 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*tmp;
	char	*tmp2;
	char	*src2;

	tmp = (char*)dst;
	tmp2 = (char*)src;
	i = 0;
	if (!(src2 = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		src2[i] = tmp2[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		tmp[i] = src2[i];
		i++;
	}
	free(src2);
	return (dst);
}
