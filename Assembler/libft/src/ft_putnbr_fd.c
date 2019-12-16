/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 18:53:33 by azouiten          #+#    #+#             */
/*   Updated: 2018/10/12 18:59:20 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	test(int n, char c, int fd)
{
	if (n >= 10 || n <= -10)
	{
		test(n / 10, c, fd);
		test(n % 10, c, fd);
	}
	else
	{
		if (n >= 0)
		{
			c = n + '0';
			write(fd, &c, 1);
		}
		else
		{
			c = (-1 * n) + '0';
			write(fd, &c, 1);
		}
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	char c;

	c = 0;
	if (n < 0)
		write(fd, "-", 1);
	test(n, c, fd);
}
