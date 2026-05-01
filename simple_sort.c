/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 18:35:38 by monika            #+#    #+#             */
/*   Updated: 2026/05/01 21:13:54 by mavanesy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_number *a, t_bench ben)
{
	if (a[0].index > a[1].index)
		sa(a, 2, ben);
	return ;
}

void	sort3(t_number *a, t_bench ben)
{
	if (a[0].index > a[1].index
		&& a[1].index < a[2].index
		&& a[0].index < a[2].index)
		sa(a, 3, ben);
	else if (a[0].index > a[1].index && a[1].index > a[2].index)
	{
		sa(a, 3, ben);
		rra(a, 3, ben);
	}
	else if (a[0].index > a[1].index
		&& a[1].index < a[2].index
		&& a[0].index > a[2].index)
		ra(a, 3, ben);
	else if (a[0].index < a[1].index
		&& a[1].index > a[2].index
		&& a[0].index < a[2].index)
	{
		sa(a, 3, ben);
		ra(a, 3, ben);
	}
	else if (a[0].index < a[1].index
		&& a[1].index > a[2].index
		&& a[0].index > a[2].index)
		rra(a, 3, ben);
}

void	find_min(t_data *meow, t_bench ben)
{
	int	min;
	int	i;

	i = 0;
	min = 0;
	while (i < meow.size1)
	{
		if (meow.a[i].index < meow.a[min].index)
			min = i;
		i++;
	}
	if (min <= *size1 / 2)
		while (min-- > 0)
			ra(a, *size1, ben);
	else
	{
		min = *size1 - min;
		while (min-- > 0)
			rra(a, *size1, ben);
	}
	pb(meow, ben);
}

int	simple_sort(t_number *a, int *size1, t_bench b)
{
	t_data	meow;
	int		p;

	meow.a = a;
	meow.size1 = &size1;
	if (*size1 <= 3)
	{
		if (*size1 == 2)
			sort2(a, ben);
		else if (*size1 == 3)
			sort3(a, ben);
		return (0);
	}
	p = *size1 - 3;
	meow.size2 = 0;
	meow.b = malloc(sizeof(t_number) * (*size1));
	if (!meow.b)
		return (free(a), error());
	while (p--)
		find_min(meow, ben);
	sort3(a);
	while (meow.size2 > 0)
		pa(meow, ben);
	return (free(meow.b), 0);
}
