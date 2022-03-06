/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:08:51 by jbatoro           #+#    #+#             */
/*   Updated: 2021/12/09 13:57:32 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			str_size;
	char			*new_string;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	str_size = ft_strlen(s1);
	while (str_size && ft_strchr(set, s1[str_size]))
		str_size--;
	new_string = ft_substr((char *)s1, 0, str_size + 1);
	return (new_string);
}
