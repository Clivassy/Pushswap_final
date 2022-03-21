/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:53:11 by jbatoro           #+#    #+#             */
/*   Updated: 2022/03/20 16:18:45 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*element;

	element = malloc(sizeof(*element));
	if (!element)
		return (NULL);
	element->content = content;
	element->next = NULL;
	return (element);
}

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

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}
