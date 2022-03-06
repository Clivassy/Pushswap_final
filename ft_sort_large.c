#include "push_swap.h"

// Index the stack in ascending order
int    *ft_sort_tab(t_list *a, int *tab)
{
    int i;
    int j;
    int temp;

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

// Sort numbers of the stack stored in array 
int    ft_get_index(t_list *a, int ac, char **av)
{
    int index;
	int *tab;

	tab = malloc(sizeof(int) * ft_len_malloc_tab(ac, av) + 1); 
    if (!tab)
        return (0);
    index = 0;
	tab = ft_create_tab(ac, av);
    ft_sort_tab(a, tab);
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
	return (0);
}

int	get_max_bits(t_list **stack)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head) // on cherche le plus grand nb
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0) // on compte le nombre de nb de bits 
		max_bits++;
	//printf("%d\n", max_bits);
	return (max_bits);
}

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
	max_bits = get_max_bits(a); // chercher cb de bits a l'élément le plus grand 
	while (i < max_bits) // a répéter pour chaque digits 
	{
		j = 0; // pour parcourir 
		while (j++ < size)
		{
			head_a = *a;
			// transform into binary form
			if (((head_a->index >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
		}
		while (ft_lstsize(*b) != 0)
			pa(a, b);
		i++;
		//printList(*a);
	}
}