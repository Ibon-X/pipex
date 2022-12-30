/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipresno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:46:23 by ipresno-          #+#    #+#             */
/*   Updated: 2022/09/15 13:38:03 by ipresno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_counter(const char *str, char c)
{
	size_t	words;

	words = 0;
	while (*str && *str == c)
		str++;
	while (*str)
	{
		while (*str && *str != c)
			str++;
		while (*str && *str == c)
			str++;
		words++;
	}
	return (words);
}

static char	*ft_splitdup(const char *str, size_t start, size_t finish)
{
	char	*new;
	size_t	i;

	i = 0;
	new = (char *)malloc(sizeof(char) * (finish - start + 1));
	if (!new)
		return (NULL);
	while (start < finish)
		new[i++] = str[start++];
	new[i] = '\0';
	return (new);
}

static char	**ft_fill_split(char **dest, const char *s, char c)
{
	size_t	i;
	size_t	p1;
	size_t	start;
	size_t	len;

	i = 0;
	p1 = 0;
	start = 0;
	len = ft_strlen(s);
	while (s[i])
	{
		while (s[i] != c && s[i])
		{
			i++;
			if (s[i] == c || i == len)
				dest[p1++] = ft_splitdup(s, start, i);
		}
		while (s[i] == c && s[i])
		{
			i++;
			start = i;
		}
	}
	dest[p1] = NULL;
	return (dest);
}

char	**ft_split(const char *s, char c)
{
	char	**new;

	if (!s)
		return (NULL);
	new = (char **)malloc(sizeof(char *) * (ft_word_counter(s, c) + 1));
	if (!new)
		return (NULL);
	ft_fill_split(new, s, c);
	return (new);
}
