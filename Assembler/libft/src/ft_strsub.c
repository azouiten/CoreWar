/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 00:39:50 by azouiten          #+#    #+#             */
/*   Updated: 2018/10/16 22:05:19 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	size_t	i;

	i = 0;
	if (s)
	{
		if (!(s1 = (char*)malloc(sizeof(char) * (len + 1))))
			return (0);
		while (i < len)
		{
			*(s1 + i) = *(s + start + i);
			i++;
		}
		*(s1 + i) = '\0';
		return (s1);
	}
	return (0);
}
