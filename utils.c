#include "push_swap.h"

/* void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
} */


int    ft_case_1(int *tab)
{
    if (tab[0] > tab[1] && tab[0] < tab[2] 
        && tab[1] < tab[2])
            return (1);
    else 
        return (0);
}

int ft_case_2(int *tab)
{
    if (tab[0] > tab[1] && tab[0] > tab[2]
        && tab[1] > tab[2])
        return (1);
    else 
        return (0);
}

int ft_case_3(int *tab)
{
    if (tab[0] > tab[1] && tab[0] > tab[2]
        && tab[1] < tab[2])
        return (1);
    else
        return (0);
}

int ft_case_4(int *tab)
{
    if (tab[0] < tab[1] && tab[0] < tab[2]
            && tab[1] > tab[2])
        return (1);
    else
        return (0);
}
  
int ft_case_5(int *tab)
{
    if (tab[0] < tab[1] && tab[0] > tab[2]
        && tab[1] > tab[2]) 
        return (1);
    else 
        return (0);
}

void    ft_sort_three(t_list **a)
{
    int i;
    t_list *array; 
    array = *a;
    int tab[3];

    i = 0;
    printList(*a);                                                                                                     
    while (i < 3)
    {
        tab[i] = array->content;
        array = array->next;
        i++;
    }
    ft_find_case(a, tab);
}

void   ft_find_case(t_list **a, int *tab)
{
    if (ft_case_1(tab))
        sa(a);
    else if (ft_case_2(tab))
    {
        sa(a);
        rra(a);
    }
    else if (ft_case_3(tab))
        ra(a);
    else if (ft_case_4(tab))
    {
        sa(a);
        ra(a);
    }
    else if (ft_case_5(tab))
        rra(a);
    printList(*a);
}