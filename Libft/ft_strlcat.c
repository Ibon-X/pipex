/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipresno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:26:56 by ipresno-          #+#    #+#             */
/*   Updated: 2022/09/14 16:49:47 by ipresno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	i;	

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	i = 0;
	if ((len_dest + 1) > n)
		return (len_src + n);
	else
	{
		while (src[i] && (len_dest + 1 + i) < n)
		{	
			dest[len_dest + i] = src[i];
			i++;
		}
	}
	dest[len_dest + i] = '\0';
	return (len_dest + len_src);
}
