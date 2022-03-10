#include "push_swap.h"

/* First element become the last one of the list (ra, rb, rr)*/
int	ft_rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack) <= 1)
		return (0);
	head = *stack;
	tail = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (1);
}
/* ra */

int	ra(t_list **a)
{
	if (ft_rotate(a))
	{
		ft_putendl_fd("ra", 1);
		return (1);
	}
	return (0);
}

/* rb */
int	rb(t_list **b)
{
	if (ft_rotate(b))
	{
		ft_putendl_fd("rb", 1);
		return (1);
	}
	return (0);
}

/* rr */
int	rr(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) <= 1 || ft_lstsize(*b) <= 1)
		return (0);
	if (ft_rotate(a) && ft_rotate(b))
	{
		ft_putendl_fd("rr", 1);
		return (1);
	}
	return (0);
}
