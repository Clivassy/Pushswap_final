#include "push_swap.h"

void	ft_no_leaks(int ac, char **input)
{
	if (ac == 2)
		ft_free(input);
}

int	ft_check_all(int tmp, char **input, int pars_args)
{
	if (ft_check_double(tmp, input, pars_args)
		&& ft_check_int_overflow(input[pars_args])
		&& ft_check_argv_input(input[pars_args]))
		return (1);
	else
		return (0);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
	free(str);
}

void	ft_free_stack(t_list *stack)
{
	t_list	*tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
