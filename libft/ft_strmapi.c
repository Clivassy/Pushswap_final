/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:58:25 by jbatoro           #+#    #+#             */
/*   Updated: 2021/12/08 18:14:49 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*string;
	unsigned int	i;
	int				len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	string = (char *)malloc(sizeof(char) * len + 1);
	if ((!string))
		return (NULL);
	i = 0;
	while (s[i])
	{
		string[i] = (*f)(i, s[i]);
		i++;
	}
	string[i] = '\0';
	return (string);
}
