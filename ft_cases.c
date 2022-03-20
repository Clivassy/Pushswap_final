/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:52:49 by jbatoro           #+#    #+#             */
/*   Updated: 2022/03/20 15:52:53 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_case_1(int *tab)
{
	if (tab[0] > tab[1] && tab[0] < tab[2]
		&& tab[1] < tab[2])
		return (1);
	else
		return (0);
}

int	ft_case_2(int *tab)
{
	if (tab[0] > tab[1] && tab[0] > tab[2]
		&& tab[1] > tab[2])
		return (1);
	else
		return (0);
}

int	ft_case_3(int *tab)
{
	if (tab[0] > tab[1] && tab[0] > tab[2]
		&& tab[1] < tab[2])
		return (1);
	else
		return (0);
}

int	ft_case_4(int *tab)
{
	if (tab[0] < tab[1] && tab[0] < tab[2]
		&& tab[1] > tab[2])
		return (1);
	else
		return (0);
}

int	ft_case_5(int *tab)
{
	if (tab[0] < tab[1] && tab[0] > tab[2]
		&& tab[1] > tab[2])
		return (1);
	else
		return (0);
}
