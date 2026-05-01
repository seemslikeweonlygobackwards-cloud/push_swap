/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 20:02:13 by mavanesy          #+#    #+#             */
/*   Updated: 2026/05/01 22:23:43 by mavanesy         ###   ########.fr       */
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

void	ra(t_data *meow, t_bench *ben)
{
	rotate(meow->a, meow->size1);
	ben->ra++;
	write(1, "ra\n", 3);
}

void	rb(t_data *meow, t_bench *ben)
{
	rotate(meow->b, meow->size2);
	ben->rb++;
	write(1, "rb\n", 3);
}

void	rr(t_data *meow, t_bench *ben)
{
	rotate(meow->a, meow->size1);
	rotate(meow->b, meow->size2);
	ben->rr++;
	write(1, "rr\n", 3);
}
