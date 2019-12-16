/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 19:50:26 by azouiten          #+#    #+#             */
/*   Updated: 2018/10/15 22:35:01 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	int		i;
	t_list	*ret;

	ret = 0;
	new = (t_list*)malloc(sizeof(t_list));
	i = 0;
	while (lst != NULL)
	{
		new->next = (t_list*)malloc(sizeof(t_list));
		new->next = f(lst);
		lst = lst->next;
		if (i == 0)
			ret = new->next;
		new = new->next;
		i++;
	}
	return (ret);
}
