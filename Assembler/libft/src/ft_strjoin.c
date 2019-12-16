/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 08:46:12 by azouiten          #+#    #+#             */
/*   Updated: 2018/10/16 19:40:58 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(const char *s)
{
	int i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*sj;
	int		i;
	int		s1s;
	int		s2s;

	s1s = ft_len(s1);
	s2s = ft_len(s2);
	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!(sj = (char*)malloc(sizeof(char) * (s1s + s2s + 1))))
		return (NULL);
	while (*(s1 + i) != '\0' && s1 != 0)
	{
		*(sj + i) = *(s1 + i);
		i++;
	}
	while (*(s2 + i - s1s) != '\0' && s2 != 0)
	{
		*(sj + i) = *(s2 + i - s1s);
		i++;
	}
	*(sj + i) = '\0';
	return (sj);
}
