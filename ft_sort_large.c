/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:54:19 by jbatoro           #+#    #+#             */
/*   Updated: 2022/03/20 15:54:23 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Index the stack in ascending order */
int	*ft_sort_tab(t_list *a, int *tab)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	temp = 0;
	while (i < ft_lstsize(a))
	{
		j = i + 1;
		while (j < ft_lstsize(a))
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

/* Sort numbers of the stack stored in array */
void	ft_get_index(t_list *a, int ac, char **av)
{
	int	index;
	int	*tab;

	tab = ft_create_tab(ac, av);
	ft_sort_tab(a, tab);
	index = 0;
	while (a)
	{
		if (tab[index] == a->content)
		{
			a->index = index;
			a = a->next;
			index = -1;
		}
		index++;
	}
	free (tab);
}
/* Find the max number && count its bits */

int	get_max_bits(t_list **stack)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}		

void	ft_fill_a(t_list **a, t_list **b)
{
	while (ft_lstsize(*b) != 0)
		pa(a, b);
}

/* Algo de tri RADIX */
void	radix_sort(t_list **a, t_list **b)
{
	t_list	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = *a;
	size = ft_lstsize(head_a);
	max_bits = get_max_bits(a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *a;
			if (((head_a->index >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
		}
		ft_fill_a(a, b);
		i++;
	}
	ft_free_stack(*a);
}
