#include "push_swap.h"

int	ft_count_words(char const *s, char c)
{
	size_t		i;
	int			count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

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
}