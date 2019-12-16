/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:45:51 by azouiten          #+#    #+#             */
/*   Updated: 2019/12/16 18:10:57 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	char	*ft_exit(char **buf, char **str)
{
	ft_strdel(buf);
	ft_strdel(str);
	return (NULL);
}

static	int		ft_strinit(char **buf, char **str)
{
	if (!(*buf = strdup(" ")))
		return (0);
	if (!(*str = strdup("")))
		return (0);
	return (1);
}

char			*get_next_line(int fd)
{
	char	*buf;
	char	*str;
	char	*tmp;
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	if (!(ft_strinit(&buf, &str)))
		return (NULL);
	while ((ret = read(fd, buf, 1)) && buf[0] != '\n')
	{
		i++;
		if (ret < 0)
			return (ft_exit(&buf, &str));
		buf[ret] = '\0';
		tmp = str;
		str = ft_strjoin(str, buf);
		ft_strdel(&tmp);
	}
	if (ret == 0 && i == 0)
		ft_strdel(&str);
	ft_strdel(&buf);
	return (str);
}
