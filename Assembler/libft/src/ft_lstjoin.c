/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 11:38:02 by azouiten          #+#    #+#             */
/*   Updated: 2018/10/17 14:20:40 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstjoin(t_list *lst, t_list *lstt)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = lstt;
	return (lst);
}
