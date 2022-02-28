#include "push_swap.h"

int	ft_is_sorted(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->content > head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
}

void    ft_sort_small_stack(t_list **a,t_list **b, int ac, char **av)
{
    int *tab;
    int pos;
    char **input;
   
    if (ac > 2)
        tab = ft_create_tab_from_av(ac, av);
  /*   if (ac == 2)
    {
        input = ft_split(av[1], ' ');
        tab = ft_create_tab_from_str(ac, ft_split(av[1], ' '));
    } */
   // printf("%d %d %d %d\n", tab[0],tab[1], tab[2],tab[3]);
    pos = ft_min_position(a, tab);
   // printf("%d %d %d %d\n", tab[0],tab[1], tab[2],tab[3]);
    if (ft_lstsize(*a) <= 1 || ft_is_sorted(a))
        return;
    else if (ft_lstsize(*a) == 2)
        ft_sort_two_nb(a, tab);
    else if (ft_lstsize(*a) == 3)
        ft_sort_three(a);
    else if (ft_lstsize(*a) == 4)
        ft_sort_four(a, b, pos);
    else 
        ft_sort_five(a, b, pos); 
    free(tab);
} 

void    ft_sort_two_nb(t_list **stack, int *tab)
{
    if (tab[0] > tab[1])
        sa(stack);
}

/*void   ft_sort_three(t_list **a)
{
    t_list *array; 

    array = *a;
    int i;
    int tab[3];

    i = 0;
    while (i < 3)
    {
        tab[i] = array->content;
        array = array->next;
        i++;
    } 
    if (tab[0] > tab[1] && tab[0] < tab[2] 
        && tab[1] < tab[2])
            sa(a);
    else if (tab[0] > tab[1] && tab[0] > tab[2]
        && tab[1] > tab[2])
    {
        sa(a);
        rra(a);
    }
    else if (tab[0] > tab[1] && tab[0] > tab[2]
        && tab[1] < tab[2])
            ra(a);
    else if (tab[0] < tab[1] && tab[0] < tab[2]
        && tab[1] > tab[2])
    {
        sa(a);
        ra(a);
    }
    else if (tab[0] < tab[1] && tab[0] > tab[2]
        && tab[1] > tab[2]) 
            rra(a);
}*/

int     ft_min_position(t_list **stack, int *tab)
{
    int i;
    int position;

    i = 1;
    position = 0;
    //printf("%d %d %d %d\n", tab[0],tab[1], tab[2],tab[3]);
    while (i < ft_lstsize(*stack))
    {   
        if (tab[i] < tab[position])
            position = i;
        i++;
    }
    return (position);
}

void    ft_sort_four(t_list **a, t_list **b, int pos)
{
    if (ft_is_sorted(a))
        return;
    if (pos == 1)
        ra(a);
    else if (pos == 2)
    {
        ra(a);
        ra(a);
    }
    else if (pos == 3)
        rra(a);
    if (ft_is_sorted(a))
        return;
    pb(a, b);
    ft_sort_three(a);
    pa(a,b);
    printList(*a);
}

void       ft_sort_five(t_list **a, t_list **b, int pos)
{
    if (pos == 1)
        ra(a);
    else if (pos == 2)
    {
        ra(a);
        ra(a);
    }
    else if (pos == 3)
    {
        rra(a);
        rra(a);
    }
    else if (pos == 4)
    {
        rra(a);
    }   
    pb(a, b);
    ft_sort_four(a, b, ft_get_pos(a));
    pa(a, b);
    printList(*a);
}

int ft_get_min(t_list **a)
{
    int min;
    t_list *temp_a;

    temp_a = *a;
    min = 2147483647;
    if (temp_a)
    {
        while (temp_a != NULL)
        {
            if (min > temp_a->content)
                min = temp_a->content;
            temp_a = temp_a->next;
        }
        return (min);
    }
    return (0);
}

int  ft_get_pos(t_list **a)
{
    int pos;
    int min;
    t_list *temp_a;

    pos = 0;
    temp_a = *a;
    min = ft_get_min(a);
    while (temp_a != NULL)
    {
        if (temp_a->content != min)
            pos++;
        else
            return(pos);
        temp_a = temp_a->next;
    }
    return (pos);
}