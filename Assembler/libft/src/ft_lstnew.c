/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 13:35:33 by azouiten          #+#    #+#             */
/*   Updated: 2018/10/16 20:00:12 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*copie;
	char	*tmp;
	size_t	i;

	if (!(copie = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		copie->content = NULL;
		copie->content_size = 0;
		copie->next = NULL;
		return (copie);
	}
	if (!(tmp = (char*)malloc(content_size * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < content_size)
	{
		tmp[i] = *(char*)(content + i);
		i++;
	}
	copie->content = tmp;
	copie->content_size = content_size;
	copie->next = NULL;
	return (copie);
}
