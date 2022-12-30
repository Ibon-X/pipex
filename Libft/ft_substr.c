/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipresno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:23:59 by ipresno-          #+#    #+#             */
/*   Updated: 2022/09/15 14:01:37 by ipresno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	strlen;
	char	*new;

	strlen = ft_strlen(s);
	if (start > strlen)
		return (ft_strdup(""));
	if (strlen < len)
		len = ft_strlen(s);
	new = (char *)malloc(sizeof(*s) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		new[i] = s[start];
		i++;
		start++;
	}
	new[i] = '\0';
	return (new);
}
