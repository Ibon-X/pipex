/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipresno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:53:43 by ipresno-          #+#    #+#             */
/*   Updated: 2022/09/14 12:54:27 by ipresno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*str2 == '\0')
		return ((char *)str1);
	while (str1[i] && i < n)
	{
		j = 0;
		while ((str1[i + j] == str2[j]) && (i + j) < n)
		{
			j++;
			if (str2[j] == '\0')
				return ((char *)&str1[i]);
		}
		i++;
	}
	return (NULL);
}
