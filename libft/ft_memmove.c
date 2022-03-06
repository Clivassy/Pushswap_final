/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:29:12 by jbatoro           #+#    #+#             */
/*   Updated: 2021/12/06 09:29:26 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*source;
	char			*dst;

	source = (char *)src;
	dst = (char *)dest;
	if (!dest && !source)
		return (dst);
	if (dst > source)
	{
		while (n)
		{
			dst[n - 1] = source[n - 1];
			n--;
		}
	}
	else
	{
		ft_memcpy(dst, source, n);
	}
	return (dst);
}
