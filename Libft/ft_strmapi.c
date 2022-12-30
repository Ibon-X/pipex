/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipresno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:35:47 by ipresno-          #+#    #+#             */
/*   Updated: 2022/09/15 13:44:24 by ipresno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *str, char (*ft)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*new;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new[i] = ft(i, str[i]);
		i++;
	}	
	new[i] = '\0';
	return (new);
}
