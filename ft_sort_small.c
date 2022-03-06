#include "push_swap.h"

void    ft_sort_two_nb(t_list **stack, int *tab)
{
    if (tab[0] > tab[1])
        sa(stack);
}

void    ft_sort_three(t_list **a)
{
    int i;
    t_list *array; 
    array = *a;
    int tab[3];

    i = 0;                                                                                                   
    while (i < 3)
    {
        tab[i] = array->content;
        array = array->next;
        i++;
    }
    ft_find_case(a, tab);
    //printList(*a);
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
    //printList(*a);
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
}

void    ft_sort_small_stack(t_list **a,t_list **b, int ac, char **av)
{
    int *tab;
    int pos;
    
    if (ac > 2)
        tab = ft_create_tab(ac, av);
    pos = ft_get_pos(a);
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
    //free (tab);
} 
