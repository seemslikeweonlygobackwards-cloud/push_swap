/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 20:55:38 by mavanesy          #+#    #+#             */
/*   Updated: 2026/05/01 22:31:52 by mavanesy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chunk_up(int size)
{
	int	chunks;

	chunks = size / 20;
	if (chunks < 5)
		return (5);
	return (chunks);
}

void	push_chunks(t_data *meow, t_bench *ben)
{
	int	chunks;
	int	current;
	int	loops;
	int	size;

	chunks = chunk_up(meow->size1);
	current = 1;
	while (current <= chunks && meow->size1 > 0)
	{
		loops = 0;
		size = meow->size1;
		while (loops < size)
		{
			if (meow->a[0].index <= current * 20)
				pb(meow, ben);
			else if (meow->size1 > 1)
				ra(meow, ben);
			loops++;
		}
		current++;
	}
}

void	helper(t_data *meow, t_bench *ben)
{
	int	max;
	int	i;

	while (meow->size2 > 0)
	{
		i = meow->size2 - 1;
		max = 0;
		while (i > 0)
		{
			if (meow->b[i].index > meow->b[max].index)
				max = i;
			i--;
		}
		if (max <= meow->size2 / 2)
			while (max-- > 0)
				rb(meow, ben);
		else
		{
			i = meow->size2 - max;
			while (i-- > 0)
				rrb(meow, ben);
		}
		pa(meow, ben);
	}
}

int	medium_sort(t_number *a, int *size1, t_bench *ben)
{
	t_data	meow;

	meow.a = a;
	meow.size1 = *size1;
	meow.size2 = 0;
	meow.b = malloc(sizeof(t_number) * meow.size1);
	if (!meow.b)
		return (free(a), error());
	push_chunks(&meow, ben);
	helper(&meow, ben);
	*size1 = meow.size1;
	free(meow.b);
	return (0);
}