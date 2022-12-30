/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipresno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:13:05 by ipresno-          #+#    #+#             */
/*   Updated: 2022/09/14 17:38:12 by ipresno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	while (*str1 && (*str1 == *str2) && n)
	{	
		str1++;
		str2++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char) *str1 - (unsigned char) *str2);
}
