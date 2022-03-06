#include "push_swap.h"

//Push element from one stack to another (pa // pb) 
int	ft_push(t_list **stack_to, t_list **stack_from)
{
	t_list	*tmp;
	t_list	*head_to;
	t_list	*head_from;

	if (ft_lstsize(*stack_from) == 0)
		return (0);
	head_to = *stack_to; 
	head_from = *stack_from;
	tmp = head_from; // copie de la liste qu'on va copier
	//printList(head_from);
	//printf("%d\n", head_from->content);
	head_from = head_from->next; // on fait pointer sur le deuxième element de la liste. 
	//printf("%d\n", head_from->content);
	*stack_from = head_from; // la nouvelle stack sans le premier element. 
	//printf("%d\n", tmp->next->content);
	if (!head_to) // si head_to est vide 
	{
		head_to = tmp; // on copie toute la liste
		head_to->next = NULL; // on supprime tout a part le 1er element.
		*stack_to = head_to; // on copie le resultat dans stack_to. 
	}
	else // si head_to n'est pas vide 
	{
		tmp->next = head_to; // je copie head_to apres le premier element de la stack dans tmp
		*stack_to = tmp; // je copie la stack finale ds la vraie stack. 
	}
	return (1);
}

/* pa */
int     pa(t_list **a, t_list **b)
{
	if (ft_push(a, b))
	{
		ft_putendl_fd("pa", 1);
		return (1);  
	}
	return (0);      
}

/* pb */
int     pb(t_list **a, t_list **b)
{
	if (ft_push(b, a))
	{
		ft_putendl_fd("pb", 1);
		return(1);  
	}
	return (0);      
}
