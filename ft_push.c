#include "push_swap.h"

/*Push element from one stack to another (pa // pb)*/
int	ft_push(t_list **to_push, t_list **get_from)
{
	t_list	*temp;
	t_list	*top_to_push;
	t_list	*top_get_from;

	if (ft_lstsize(*get_from) == 0)
		return (0);
	top_to_push = *to_push;
	top_get_from = *get_from;
	temp = top_get_from;
	top_get_from = top_get_from->next;
	*get_from = top_get_from;
	if (!top_to_push)
	{
		top_to_push = temp;
		top_to_push->next = NULL;
		*to_push = top_to_push;
	}
	else
	{
		temp->next = top_to_push;
		*to_push = temp;
	}
	return (1);
}

/* pa */
int	pa(t_list **a, t_list **b)
{
	if (ft_push(a, b))
	{
		ft_putendl_fd("pa", 1);
		return (1);
	}
	return (0);
}

/* pb */
int	pb(t_list **a, t_list **b)
{
	if (ft_push(b, a))
	{
		ft_putendl_fd("pb", 1);
		return (1);
	}
	return (0);
}
