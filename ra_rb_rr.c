/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 20:02:13 by mavanesy          #+#    #+#             */
/*   Updated: 2026/04/18 17:48:59 by mavanesy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(int *stack, int size)
{
	int	first;
	int	i;

	if (size < 2)
		return ;
	first = stack[0];
	i = 0;
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[size - 1] = first;
}

void	ra(int *a, int size1)
{
	rotate(a, size1);
	write(1, "ra\n", 3);
}

void	rb(int *b, int size2)
{
	rotate(b, size2);
	write(1, "rb\n", 3);
}

void	rr(int *a, int *b, int size1, int size2)
{
	rotate(a, size1);
	rotate(b, size2);
	write(1, "rr\n", 3);
}
