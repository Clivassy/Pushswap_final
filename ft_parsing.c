#include "push_swap.h"

int		ft_tab_len(int ac, char *av)
{
	int len;

	len = 0; 
	while (len < ac - 1)
		len++;
	return (len);
}

// Atoi to convert argv into numbers
int	ft_atoi(const char *nptr)
{
	long	nb;
	int		i;
	int		signe;

	nb = 0;
	i = 0;
	signe = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13)
		|| (nptr[i] == 32))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			signe = -signe;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - 48);
		i++;
	}
	return (nb * signe);
}

t_list *ft_create_list(int ac, char **argv, t_list **stack_a)
{
    int i;
    int *tab;
	int len; 
    t_list *temp;

    if (ac == 2)
	{
		len = ft_count_words(argv[1], ' ');
		tab = ft_create_tab_from_str(ac, argv);
		//printf("%d\n", len);
	}   
    else
	{
		len = ft_tab_len(ac, argv[1]);
    	tab = ft_create_tab_from_av(ac, argv);
	} 
    i = 0; 
    while (i < len)
    {   
		//printf("%d\n", tab[i]);
		temp = ft_lstnew(tab[i]);
		ft_lstadd_back(stack_a, temp);
        i++;
    }
	free(temp);
    return (*stack_a);
}