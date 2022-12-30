/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipresno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:52:12 by ipresno-          #+#    #+#             */
/*   Updated: 2022/09/14 13:10:17 by ipresno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*new;
	size_t	len;

	len = ft_strlen(str);
	new = (char *)malloc(sizeof(*str) * (len + 1));
	if (!new)
		return (NULL);
	ft_memcpy(new, str, len + 1);
	return (new);
}
