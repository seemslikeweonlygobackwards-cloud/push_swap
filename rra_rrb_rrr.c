/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 23:23:07 by amghazar          #+#    #+#             */
/*   Updated: 2026/05/01 22:57:05 by mavanesy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_number *stack, int size)
{
	t_number	temp;
	int			i;

	if (size < 2)
		return ;
	temp = stack[size - 1];
	i = size - 1;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = temp;
}

void	rra(t_data *meow, t_bench *ben)
{
	reverse_rotate(meow->a, meow->size1);
	ben->rra++;
	write(1, "rra\n", 4);
}

void	rrb(t_data *meow, t_bench *ben)
{
	reverse_rotate(meow->b, meow->size2);
	ben->rrb++;
	write(1, "rrb\n", 4);
}

void	rrr(t_data *meow, t_bench *ben)
{
	reverse_rotate(meow->a, meow->size1);
	reverse_rotate(meow->b, meow->size2);
	ben->rrr++;
	write(1, "rrr\n", 4);
}
