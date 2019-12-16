/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strndup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 15:12:26 by azouiten          #+#    #+#             */
/*   Updated: 2018/10/17 16:11:24 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*s;

	s = (char*)malloc(sizeof(char) * (n + 1));
	if (s == NULL)
		return (NULL);
	s = ft_strncpy(s, (const char*)s1, n);
	return (s);
}
