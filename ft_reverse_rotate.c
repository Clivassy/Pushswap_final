#include "push_swap.h"

/* Last element become the firts one of the list (rra, rrb, rrr) */
int	ft_reverse_rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack) <= 1)
		return (0);
	head = *stack;
	tail = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	return (1);
}

int	rra(t_list **a)
{
	if (ft_reverse_rotate(a))
	{
		ft_putendl_fd("rra", 1);
		return (1);
	}
	return (0);
}

int	rrb(t_list **b)
{
	if (ft_reverse_rotate(b))
	{
		ft_putendl_fd("rrb", 1);
		return (1);
	}
	return (0);
}

int	rrr(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) <= 1 || ft_lstsize(*b) <= 1)
		return (0);
	if (ft_reverse_rotate(a) && ft_reverse_rotate(b))
	{
		ft_putendl_fd("rrr", 1);
		return (1);
	}
	return (0);
}
