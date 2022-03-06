#include "push_swap.h"

/* Print error message */
int	ft_print_error(void)
{
	ft_putendl_fd("Error", 1);
	return (0);
}

/* Check there are only numbers (including one previous + or - only) */
int	ft_check_argv_input(char *nptr)
{
	int		i;
	int		signe;

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
		return (0);
return (1);
}

/* Check int overflow */
int	ft_check_int_overflow(char *arg)
{
	long long	nb;

	nb = ft_atol(arg);
	if (nb >= INT_MIN && nb <= INT_MAX)
		return (1);
	return (0);
}

/* Check doubles */
int	ft_check_double(int num, char **input, int i)
{
	i++;
	while (input[i])
	{
		if (ft_atoi(input[i]) == num)
			return (0);
		i++;
	}
	return (1);
}

/* Combine all checking errors */
int	ft_check_errors(int argc, char **argv)
{
	int		pars_args;
	char	**input;
	int		tmp;

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
		tmp = ft_atoi(input[pars_args]);
		if (ft_check_double(tmp, input, pars_args)
			&& ft_check_int_overflow(input[pars_args])
			&& ft_check_argv_input(input[pars_args]))
			pars_args++;
		else
			return (ft_print_error());
	}
	if (argc == 2)
		free(input);
	return (1);
}
