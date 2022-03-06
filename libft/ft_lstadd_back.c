/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 18:09:09 by jbatoro           #+#    #+#             */
/*   Updated: 2021/12/08 18:20:57 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*temp;

	if (alst)
	{
		if (!*alst)
			*alst = new;
		else
		{
			temp = (*alst);
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new;
		}
	}
}
