/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipresno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:53:04 by ipresno-          #+#    #+#             */
/*   Updated: 2022/09/15 13:04:41 by ipresno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	char	*s1;

	i = ft_strlen(str) + 1;
	s1 = (char *)str;
	while (i--)
	{
		if (s1[i] == (char)c)
			return (&s1[i]);
	}
	return (NULL);
}
