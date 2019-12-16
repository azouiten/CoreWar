/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 03:47:46 by azouiten          #+#    #+#             */
/*   Updated: 2018/10/16 19:37:33 by azouiten         ###   ########.fr       */
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

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*sr;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	sr = (char*)malloc(sizeof(char) * (ft_len(s) + 1));
	if (sr == NULL)
		return (NULL);
	while (*(s + i) != '\0')
	{
		*(sr + i) = f((char)*(s + i));
		i++;
	}
	*(sr + i) = '\0';
	return (sr);
}
