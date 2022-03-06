/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:55:30 by jbatoro           #+#    #+#             */
/*   Updated: 2021/12/01 20:06:23 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dst;
	const char	*source;

	if (!dest && !src)
		return (NULL);
	dst = (char *)dest;
	source = (const char *)src;
	i = 0;
	while (i < n)
	{
		dst[i] = source[i];
		i++;
	}
	return (dst);
}
