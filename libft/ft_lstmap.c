/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:16:46 by jbatoro           #+#    #+#             */
/*   Updated: 2021/12/09 14:14:31 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new_list;

	if (!lst)
		return (0);
	new_list = ft_lstnew((*f)(lst->content));
	if (!new_list)
		return (0);
	temp = new_list;
	lst = lst->next;
	while (lst)
	{
		temp->next = ft_lstnew((*f)(lst->content));
		if (!temp->next)
		{
			ft_lstclear(&new_list, del);
			return (0);
		}
		temp = temp->next;
		lst = lst->next;
	}
	return (new_list);
}
