/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:26:08 by jbatoro           #+#    #+#             */
/*   Updated: 2021/12/02 14:38:04 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	src_size;
	char	*dest;
	char	*source;
	int		i;

	i = 0;
	source = (char *)s;
	src_size = ft_strlen(s);
	dest = (char *)malloc(src_size * sizeof(char) + 1);
	if (!dest)
		return (NULL);
	while (source[i])
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
