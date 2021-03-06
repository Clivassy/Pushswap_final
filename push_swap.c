/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:55:20 by jbatoro           #+#    #+#             */
/*   Updated: 2022/03/20 15:55:22 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (ft_check_errors(argc, argv))
	{
		ft_create_list(argc, argv, &a);
		if (ft_is_sorted(&a))
		{
			ft_free_stack(a);
			return (0);
		}
		if (ft_lstsize(a) <= 5)
			ft_sort_small(&a, &b);
		if (ft_lstsize(a) > 5)
		{
			ft_get_index(a, argc, argv);
			radix_sort(&a, &b);
		}
		ft_free_stack(a);
	}
	return (0);
}
