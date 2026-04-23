/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monika <monika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 23:23:07 by amghazar          #+#    #+#             */
/*   Updated: 2026/04/23 22:07:21 by monika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_number *stack, int size)
{
	int	last;
	int	i;

	if (size < 2)
		return ;
	last = stack[size - 1];
	i = size - 1;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = last;
}

void	rra(t_number *a, int size1)
{
	reverse_rotate(a, size1);
	write(1, "rra\n", 4);
}

void	rrb(t_number *b, int size2)
{
	reverse_rotate(b, size2);
	write(1, "rrb\n", 4);
}

void	rrr(t_number *a, t_number *b, int size1, int size2)
{
	reverse_rotate(a, size1);
	reverse_rotate(b, size2);
	write(1, "rrr\n", 4);
}
