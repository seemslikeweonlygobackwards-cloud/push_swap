/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 18:35:38 by monika            #+#    #+#             */
/*   Updated: 2026/05/01 22:31:13 by mavanesy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_data *meow, t_bench *ben)
{
	if (meow->a[0].index > meow->a[1].index)
		sa(meow, ben);
}

void	sort3(t_data *meow, t_bench *ben)
{
	if (meow->a[0].index > meow->a[1].index
		&& meow->a[1].index < meow->a[2].index
		&& meow->a[0].index < meow->a[2].index)
		sa(meow, ben);
	else if (meow->a[0].index > meow->a[1].index
		&& meow->a[1].index > meow->a[2].index)
	{
		sa(meow, ben);
		rra(meow, ben);
	}
	else if (meow->a[0].index > meow->a[1].index
		&& meow->a[1].index < meow->a[2].index
		&& meow->a[0].index > meow->a[2].index)
		ra(meow, ben);
	else if (meow->a[0].index < meow->a[1].index
		&& meow->a[1].index > meow->a[2].index
		&& meow->a[0].index < meow->a[2].index)
	{
		sa(meow, ben);
		ra(meow, ben);
	}
	else if (meow->a[0].index < meow->a[1].index
		&& meow->a[1].index > meow->a[2].index
		&& meow->a[0].index > meow->a[2].index)
		rra(meow, ben);
}

void	find_min(t_data *meow, t_bench *ben)
{
	int	min;
	int	i;

	i = 0;
	min = 0;
	while (i < meow->size1)
	{
		if (meow->a[i].index < meow->a[min].index)
			min = i;
		i++;
	}
	if (min <= meow->size1 / 2)
		while (min-- > 0)
			ra(meow, ben);
	else
	{
		min = meow->size1 - min;
		while (min-- > 0)
			rra(meow, ben);
	}
	pb(meow, ben);
}

int	small_cases(t_data *meow, t_bench *ben)
{
	if (meow->size1 == 2)
		sort2(meow, ben);
	else if (meow->size1 == 3)
		sort3(meow, ben);
	return (0);
}

int	simple_sort(t_number *a, int *size1, t_bench *ben)
{
	t_data	meow;
	int		p;

	meow.a = a;
	meow.size1 = *size1;
	meow.size2 = 0;
	meow.b = NULL;
	if (meow.size1 <= 3)
		return (small_cases(&meow, ben));
	p = meow.size1 - 3;
	meow.b = malloc(sizeof(t_number) * meow.size1);
	if (!meow.b)
		return (free(a), error());
	while (p--)
		find_min(&meow, ben);
	sort3(&meow, ben);
	while (meow.size2 > 0)
		pa(&meow, ben);
	*size1 = meow.size1;
	free(meow.b);
	return (0);
}
