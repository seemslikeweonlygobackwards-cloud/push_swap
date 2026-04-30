/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 20:55:38 by mavanesy          #+#    #+#             */
/*   Updated: 2026/04/30 20:24:51 by mavanesy         ###   ########.fr       */
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

void	push_chunks(t_number *a, t_number *b, int *size1, int *size2)
{
	int	chunks;
	int	current;
	int	loops;
	int	size;

	chunks = chunk_up(*size1);
	current = 1;
	while (current <= chunks && *size1 > 0)
	{
		loops = 0;
		size = *size1;
		while (loops < size)
		{
			if (a[0].index <= current * 20)
				pb(a, b, size1, size2);
			else if (*size1 > 1)
				ra(a, *size1);
			loops++;
		}
		current++;
	}
}

void	helper(t_number *a, t_number *b, int *size1, int *size2)
{
	int	max;
	int	i;

	while (*size2 > 0)
	{
		i = *size2 - 1;
		max = 0;
		while (i > 0)
		{
			if (b[i].index > b[max].index)
				max = i;
			i--;
		}
		if (max <= *size2 / 2)
			while (max-- > 0)
				rb(b, *size2);
		else
		{
			i = *size2 - max;
			while (i-- > 0)
				rrb(b, *size2);
		}
		pa(a, b, size1, size2);
	}
}

void	medium_sort(t_number *a, int *size1)
{
	t_number	*b;
	int			size2;

	b = malloc(sizeof(t_number) * size1);
	if (!b)
		return (free(a), error());
	push_chunks(a, b, size1, size2);
	helper(a, b, size1, size2)

}
