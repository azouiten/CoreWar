/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 22:23:34 by azouiten          #+#    #+#             */
/*   Updated: 2018/10/16 18:59:55 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strcat(char *s1, const char *s2)
{
	int i;
	int j;

	i = ft_len(s1);
	j = 0;
	while (j < ft_len((char*)s2))
	{
		s1[i] = (char)s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}
