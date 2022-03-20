/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:54:53 by jbatoro           #+#    #+#             */
/*   Updated: 2022/03/20 15:54:54 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swap elements in stacks (sa // sb // ss) */
int	ft_swap_nodes(t_list **stack)
{
	t_list	*head;
	t_list	*next;
	int		keep_content;
	int		keep_index;

	if (ft_lstsize(*stack) <= 1)
		return (0);
	head = *stack;
	next = head->next;
	if (!head && !next)
		return (1);
	keep_content = head->content;
	keep_index = head->index;
	head->content = next->content;
	head->index = next->index;
	next->content = keep_content;
	next->index = keep_index;
	return (1);
}

/* sa */
int	sa(t_list **a)
{
	if (ft_swap_nodes(a))
	{
		ft_putendl_fd("sa", 1);
		return (1);
	}
	return (0);
}

/* sb */
int	sb(t_list **b)
{
	if (ft_swap_nodes(b))
	{
		ft_putendl_fd("sb", 1);
		return (1);
	}
	return (0);
}

/* ss */
int	ss(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) <= 1 || ft_lstsize(*b) <= 1)
		return (0);
	if (ft_swap_nodes(a) && ft_swap_nodes(b))
	{
		ft_putendl_fd("ss", 1);
		return (1);
	}
	return (0);
}
