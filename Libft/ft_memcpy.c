/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipresno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:05:34 by ipresno-          #+#    #+#             */
/*   Updated: 2022/09/14 16:00:26 by ipresno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d1;
	unsigned char	*s1;

	if (!dest && !src)
		return (NULL);
	d1 = (unsigned char *) dest;
	s1 = (unsigned char *) src;
	while (n--)
	{
		*d1 = *s1;
		d1++;
		s1++;
	}
	return (dest);
}
