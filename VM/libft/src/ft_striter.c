/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 11:26:59 by ohachim           #+#    #+#             */
/*   Updated: 2018/10/19 21:53:42 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int		cn;

	if (s && f)
	{
		cn = 0;
		while (s[cn] != '\0')
		{
			f(&s[cn]);
			cn++;
		}
	}
}
