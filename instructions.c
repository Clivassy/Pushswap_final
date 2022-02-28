#include "push_swap.h"

// //Swap elements in stacks (sa // sb // ss)
int     ft_swap_nodes(t_list **stack)
{ 
    t_list *head;
    t_list *next;
    int     keep_content;
    int     keep_index;

    if (ft_lstsize(*stack) <= 1)
		return (0);
	head = *stack;
	next = head->next;
	if (!head && !next)
		return (1);
	keep_content = head->content; // stocker first data
	//printf("%d\n", keep_content);
	keep_index = head->index; // 0
	//printf("%d\n", keep_index);
	head->content = next->content; // 1er elem == deuxieme
	head->index = next->index; // on se rend sur le deuxieme element
	next->content = keep_content; // deuxieme element == 1er elem stocké ds keep content
	next->index = keep_index; // on replace l'index sur 1er elem. 
	return (1);
}

/* sa */
int     sa(t_list **a)
{
    if (ft_swap_nodes(a))
    {
        printf("sa\n");
        return (1);
    }
    return (0);        
}

/* sb */
int     sb(t_list **b)
{
     if (ft_swap_nodes(b))
    {
        printf("sb\n");
        return (1);
    }
    return (0); 
}

/* ss */
int     ss(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) <= 1 || ft_lstsize(*b) <= 1)
		return (0);
     if (ft_swap_nodes(a) && ft_swap_nodes(b))
    {
        printf("ss\n");
        return (1);
    }
    return (0); 
}

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
        printf("pa\n");
        return(1);  
    }
    return (0);      
}

/* pb */
int     pb(t_list **a, t_list **b)
{
    if (ft_push(b, a))
    {
        printf("pb\n");
        return(1);  
    }
    return (0);      
}

//Rotate liste : first element become the last one of the list (ra, rb, rr)
int	ft_rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack) <= 1)
		return (0);
	head = *stack;
	tail = ft_lstlast(head); // == au dernier element de la liste.
	//printList(tail);
	*stack = head->next; // on fait demarrer la liste a partir du second element.
	//printList(*stack);
	//printf("%d\n", head->content);
	head->next = NULL;
	//printf("%d\n", head->content);
	tail->next = head;
	return (1);
}
 /* ra */
int 	ra(t_list **a)
{
	if (ft_rotate(a))
    {
        printf("ra\n");
        return(1);  
    }
    return (0);  
}

/* rb */
int		rb(t_list **b)
{
	if (ft_rotate(b))
    {
        printf("rb\n");
        return(1);  
    }
    return (0);
}

/* rr */ 
int		rr(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) <= 1 || ft_lstsize(*b) <= 1)
		return (0);
	if (ft_rotate(a) && ft_rotate(b))
    {
        printf("rb\n");
        return(1);  
    }
    return (0);
}

//Reverse Rotate liste : last element become the firts one of the list (rra, rrb, rrr)
int		ft_reverseRotate(t_list **stack)
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

int		rra(t_list **a)
{
	if (ft_reverseRotate(a))
    {
        printf("rra\n");
        return(1);  
    }
    return (0);
}

int		rrb(t_list **b)
{
	if (ft_reverseRotate(b))
    {
        printf("rra\n");
        return(1);  
    }
    return (0);
}

int		rrr(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) <= 1 || ft_lstsize(*b) <= 1)
		return (0);
	if (ft_reverseRotate(a) && ft_reverseRotate(b))
    {
        printf("rra\n");
        return(1);  
    }
    return (0);
}