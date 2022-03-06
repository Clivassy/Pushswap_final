/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:22:22 by jbatoro           #+#    #+#             */
/*   Updated: 2021/12/01 20:04:05 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	letter;

	i = 0;
	str = (unsigned char *)s;
	letter = (unsigned char)c;
	while (i < n)
	{
		if (*str == letter)
			return (str);
		i++;
		str++;
	}
	return (NULL);
}
