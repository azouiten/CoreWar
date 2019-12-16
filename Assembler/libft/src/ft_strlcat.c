/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 15:52:49 by azouiten          #+#    #+#             */
/*   Updated: 2018/10/16 19:01:26 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t			ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	size;
	size_t	nosize;

	size = n + ft_len((char*)src);
	nosize = ft_len(dst) + ft_len((char*)src);
	i = ft_len(dst);
	j = 0;
	while (src[j] != '\0' && (int)i < (int)(n - 1))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	if (nosize > size)
		return (size);
	else
		return (nosize);
}
