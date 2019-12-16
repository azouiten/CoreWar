/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 13:49:11 by azouiten          #+#    #+#             */
/*   Updated: 2018/10/16 18:56:18 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_len(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char			*ft_strdup(const char *s1)
{
	int		i;
	char	*s;

	i = 0;
	s = (char*)malloc(sizeof(char) * (ft_len((char*)s1) + 1));
	if (s == NULL)
		return (NULL);
	while (i < ft_len((char*)s1))
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
