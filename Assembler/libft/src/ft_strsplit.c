/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 12:46:14 by azouiten          #+#    #+#             */
/*   Updated: 2018/10/16 20:16:05 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_testwords(char const *s, char c)
{
	int i;
	int cp;

	cp = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			cp++;
		i++;
	}
	return (cp);
}

static int	ft_alphabet(const char *s, char c, int *i)
{
	int cp;

	cp = 0;
	while (s[*i] != c && s[*i] != '\0')
	{
		*i += 1;
		cp++;
	}
	return (cp);
}

static char	**ft_core(char const *s, char **words, char c, int i)
{
	int j;
	int j1;
	int cp;

	j = 0;
	j1 = 0;
	cp = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		cp = ft_alphabet(s, c, &i);
		if (!(words[j] = (char*)malloc(sizeof(char) * (cp + 1))))
			return (NULL);
		j1 = 0;
		while (cp > 0)
			words[j][j1++] = s[i - cp--];
		words[j++][j1] = 0;
	}
	words[j] = 0;
	return (words);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**words;
	int		i;
	int		cp;

	i = 0;
	cp = ft_testwords(s, c);
	if (!(words = (char**)malloc(sizeof(char*) * (cp + 2))))
		return (NULL);
	i = 0;
	return (ft_core(s, words, c, i));
}
