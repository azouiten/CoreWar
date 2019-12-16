/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 01:56:53 by azouiten          #+#    #+#             */
/*   Updated: 2018/10/16 19:15:58 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;

	s = (char*)malloc(sizeof(char) * (size + 1));
	if (s == NULL)
		return (0);
	while (size + 1 > 0)
	{
		s[size--] = '\0';
	}
	return (s);
}
