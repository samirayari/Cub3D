/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:57:29 by sayari            #+#    #+#             */
/*   Updated: 2021/09/18 09:00:54 by sayari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static unsigned	int	ft_count_words(char *s, char c)
{
	unsigned int		count;

	count = 0;
	while (*s)
	{
		if (*s == '\0')
			break ;
		else if (*s != c)
		{
			count++;
			while (*s && (*s != c))
				s++;
		}
		else
			s++;
	}
	return (count);
}

char	*ft_strndup(char const *s, size_t n)
{
	char	*cp;
	size_t	i;

	i = 0;
	cp = (char *)malloc(n + 1);
	if (cp == NULL)
		return (NULL);
	while (i < n)
	{
		cp[i] = s[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	char			**tab_words;
	unsigned int	j;
	int				k;

	if (!s)
		return (NULL);
	tab_words = malloc((sizeof(char *)) * (ft_count_words((char *)s, c) + 1));
	if (tab_words == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
			tab_words[k++] = ft_strndup(s + j, i - j);
	}
	tab_words[k] = NULL;
	return (tab_words);
}
