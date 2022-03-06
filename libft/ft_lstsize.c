/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:43:24 by jbatoro           #+#    #+#             */
/*   Updated: 2021/12/08 18:15:41 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		nb_element;

	nb_element = 0;
	if (lst)
	{
		while (lst)
		{
			lst = lst->next;
			nb_element++;
		}
	}
	return (nb_element);
}
