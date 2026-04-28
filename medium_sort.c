/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 20:55:38 by mavanesy          #+#    #+#             */
/*   Updated: 2026/04/29 00:07:01 by mavanesy         ###   ########.fr       */
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

void	push_chunks(t_number *a, t_number *b, int size1, int size2)
{
	int	chunks;
	int	current;
	int	i;

	i = 0;
	chunks = chunk_up(size1);
	current = 1;
	while (current < chunks)
	{
		if (a[i].index <= current * 20)
			pb(a, b);
		else
			ra(a);
		i++;
	}
	current++;
}

void	medium_sort(t_number *a, t_number *b, int *size1, int *size2)
{
    
}