#include "push_swap.h"

int	ft_tab_len(int ac)
{
	int	len;

	len = 0;
	while (len < ac - 1)
		len++;
	return (len);
}

/* Atol to handle int overflow */
long	ft_atol(char *str)
{
	long	i;
	long	nbr;
	int		isneg;

	i = 0;
	nbr = 0;
	isneg = 0;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] != '\0' && str[i] == '-')
	{
		isneg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
		nbr = (nbr * 10) + (str[i++] - '0');
	if (isneg == 1)
		return (-nbr);
	return (nbr);
}

/* Return correct len to malloc properly the tab stocking numbers
   taille ac + taille de chaque av// ou strlen de av + 1 */
int	ft_len_malloc_tab(int ac, char **av)
{
	int	i;
	int	count;

	count = ac - 1;
	i = 1;
	while (i < ac)
	{
		count += strlen(av[i]);
		i++;
	}
	return (count);
}

/* Create tab with arg numbers */
int	*ft_create_tab(int ac, char **av)
{
	int		j;
	int		i;
	int		*tab;
	char	**input;

	tab = malloc(sizeof(int) * ft_len_malloc_tab(ac, av) + 1);
	if (!tab)
		return (NULL);
	j = 0;
	if (ac == 2)
		input = ft_split(av[1], ' ');
	else
	{
		input = av;
		j = 1;
	}
	i = 0;
	while (input[j])
		tab[i++] = ft_atoi(input[j++]);
	tab[i] = '\0';
	if (ac == 2)
		free (input);
	return (tab);
}

void	ft_create_list(int ac, char **argv, t_list **stack_a)
{
	int		i;
	int		*tab;
	int		len;
	t_list	*temp;

	if (ac == 2)
		len = ft_count_words(argv[1], ' ');
	else
		len = ft_tab_len(ac);
	tab = ft_create_tab(ac, argv);
	i = 0;
	if (len == 1)
		return ;
	while (i < len)
	{
		temp = ft_lstnew(tab[i]);
		ft_lstadd_back(stack_a, temp);
		i++;
	}
	free (tab);
}
