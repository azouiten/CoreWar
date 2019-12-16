/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 11:59:34 by azouiten          #+#    #+#             */
/*   Updated: 2018/10/16 19:51:44 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_test(char const *s, int end, int i)
{
	while (s[i] != '\0')
	{
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			end++;
		else
			end = 0;
		i++;
	}
	end = i - end;
	return (end);
}

char		*ft_strtrim(char const *s)
{
	char	*sdup;
	int		i;
	int		start;
	int		end;

	i = 0;
	start = 0;
	end = 0;
	if (!s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	start = i;
	end = ft_test(s, end, i);
	if (!(sdup = (char*)malloc(sizeof(char) * (end - start + 1))))
		return (NULL);
	i = 0;
	while (start < end)
		sdup[i++] = s[start++];
	sdup[i] = '\0';
	return (sdup);
}
