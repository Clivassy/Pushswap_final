/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:22:43 by jbatoro           #+#    #+#             */
/*   Updated: 2021/12/01 20:05:40 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*string;
	const unsigned char	*string2;

	if (n == 0)
		return (0);
	string = (const unsigned char *)s1;
	string2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (string[i] != string2[i])
			return (string[i] - string2[i]);
		i++;
	}
	return (0);
}
