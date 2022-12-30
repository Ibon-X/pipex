/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipresno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:22:02 by ipresno-          #+#    #+#             */
/*   Updated: 2022/09/15 13:06:28 by ipresno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*str1;
	char	*str2;

	if (!dest && !src)
		return (NULL);
	str1 = (char *)dest;
	str2 = (char *)src;
	if (dest > src)
	{
		while (n--)
		{
			str1[n] = str2[n];
		}		
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
