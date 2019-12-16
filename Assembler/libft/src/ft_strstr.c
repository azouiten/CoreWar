/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 17:25:38 by azouiten          #+#    #+#             */
/*   Updated: 2018/10/16 19:06:29 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char		*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int t;

	i = 0;
	j = 0;
	t = 0;
	while (haystack[i] != '\0')
	{
		j = 0;
		t = 0;
		while (needle[j] != '\0' && needle[j] == haystack[i + j])
		{
			j++;
			t = 1;
		}
		if (j == ft_len((char*)needle) && t == 1)
			return ((char*)&haystack[i]);
		i++;
	}
	j = 0;
	if (needle[j] == haystack[i])
		return ((char *)haystack);
	return (NULL);
}
