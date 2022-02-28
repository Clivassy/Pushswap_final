#include "push_swap.h"

// print message error
int   ft_print_error()
{
    write(1, "Error\n", 6);
    return (0);
    //ft_printf("Error\n");
}

// Atol to handle int overflow
long   ft_atol(char *str)
{
    long    i;
    long    nbr;
    int     isneg;

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

//Check there are only numbers (including one previous + or - only)
int     ft_check_argv_input(char *nptr)
{
   	long	nb;
	int		i;
	int		signe;

	nb = 0;
	i = 0;
	signe = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			signe = -signe;
		i++;
	}
	while (ft_isdigit(nptr[i]))
        i++; 
    if (nptr[i] != '\0')
        return(0);
	return (1);
}
//Return correct len to malloc properly the tab stocking numbers
// taille ac + taille de chaque av// taille de count_words + taille de chaque av 
int     ft_len_malloc_tab(int ac, char **av)
{
    int i;
    int count;

    count = ac - 1;
    i = 1;

    //printf("%s", av[i]);
    while (i < ac)
    {
        count += strlen(av[i]);
        //printf("%lu\n", strlen(av[i]));
        i++;
    }
    //printf("%d\n", count);
    return (count);
}

//Create tab with arg numbers
int *ft_create_tab_from_av(int ac, char **av)
{
    int j;
    int i;
    int *tab;
    char **input;

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
    return (tab);
    // penser a free
}

int *ft_create_tab_from_str(int ac, char **av)
{
    int j;
    int i;
    int *tab;
    char **input;

    tab = malloc(sizeof(int*) * 1000); // calculer bonne taille !!
    if (!tab)
        return (NULL);
    j = 0;
    input = ft_split(av[1], ' ');
    i = 0;
    while (input[j])
    {
        tab[i] = ft_atoi(input[j]);
        i++;
        j++;
    }   
    tab[i] = '\0';
   // printf("%d %d %d\n", tab[0], tab[1],tab[2]);
    return (tab);
    // il est free ds ft_check_errors
}

// Check int overflow
int    ft_check_int_overflow(char *arg)
{
    long long    nb;

    nb = ft_atol(arg);
    if (nb >= INT_MIN && nb <= INT_MAX)
        return (1);
    return (0);
}

// Check doubles
int     ft_check_double(int ac, char **av)
{
    int j;
    int i;
    int *stock_nb;


    if (ac == 2)
        stock_nb = ft_create_tab_from_str(ac, av);
    else
        stock_nb = ft_create_tab_from_av(ac, av);
    i = 0;
    j = 1;
    printf("%d %d %d\n", stock_nb[0], stock_nb[1],stock_nb[2]);
    while (stock_nb[i])
    {
        j = i + 1;
        while (stock_nb[j]) 
       /* while (av[1][j]) */
        {   
            //printf("%d %d\n", stock_nb[i] ,stock_nb[j]);
            if (stock_nb[i] == stock_nb[j])
            {
                printf("not good");
                return (0);
            }
            j++;
        }
        i++;
    }
    return (1);
}

// Combine all checking error
int     ft_check_errors(int argc, char **argv)
{
    int     pars_args;
    char    **input;

    pars_args = 0; 
    if (argc == 2)
        input = ft_split(argv[1], ' ');
    else
    {
         pars_args = 1;
         input = argv;
    }
    while (input[pars_args])
    {
        if (ft_check_double(argc, input) 
            && ft_check_int_overflow(input[pars_args]) 
            && ft_check_argv_input(input[pars_args]))
                pars_args++;
        else
        {
            ft_print_error();
            return (0);
        }
    }
    if (argc == 2)
        ft_free_tab(input);
    return (1);
}
