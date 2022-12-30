/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipresno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:05:58 by ipresno-          #+#    #+#             */
/*   Updated: 2022/09/15 13:17:38 by ipresno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	while (*str && *str != (unsigned char) c)
		str++;
	if (*str == (unsigned char)c)
		return ((char *)str);
	return (0);
}
