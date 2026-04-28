/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 20:02:13 by mavanesy          #+#    #+#             */
/*   Updated: 2026/04/28 22:43:27 by mavanesy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_number *stack, int size)
{
	t_number	temp;
	int			i;

	if (size < 2)
		return ;
	temp = stack[0];
	i = 0;
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[size - 1] = temp;
}

void	ra(t_number *a, int size1)
{
	rotate(a, size1);
	write(1, "ra\n", 3);
}

void	rb(t_number *b, int size2)
{
	rotate(b, size2);
	write(1, "rb\n", 3);
}

void	rr(t_number *a, t_number *b, int size1, int size2)
{
	rotate(a, size1);
	rotate(b, size2);
	write(1, "rr\n", 3);
}
