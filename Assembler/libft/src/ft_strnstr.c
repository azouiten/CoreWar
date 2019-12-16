/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 18:27:36 by azouiten          #+#    #+#             */
/*   Updated: 2018/10/16 19:12:31 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	int		t;

	i = 0;
	j = 0;
	t = 0;
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		t = 0;
		while (needle[j] != '\0' && needle[j] == haystack[i + j])
		{
			j++;
			t = 1;
		}
		if (j == (size_t)ft_strlen(needle) && t == 1 && i + j <= len)
			return ((char*)&haystack[i]);
		i++;
	}
	if (needle[0] == '\0')
		return ((char*)haystack);
	return (NULL);
}
