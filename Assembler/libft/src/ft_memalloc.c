/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 22:17:50 by azouiten          #+#    #+#             */
/*   Updated: 2018/10/09 00:55:50 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*s;

	s = (char*)malloc(sizeof(char) * size);
	if (s == NULL)
		return (NULL);
	while (size + 1 > 0)
		s[--size] = 0;
	return (s);
}
