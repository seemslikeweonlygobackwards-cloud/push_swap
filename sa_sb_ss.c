/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 19:40:24 by mavanesy          #+#    #+#             */
/*   Updated: 2026/05/01 21:03:07 by mavanesy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_number *stack, int size)
{
	t_number	temp;

	if (size < 2)
		return ;
	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
}

void	sa(t_number *a, int size1, t_bench ben)
{
	swap(a, size1, ben);
	ben->sa++;
	write(1, "sa\n", 3);
}

void	sb(t_number *b, int size2, t_bench ben)
{
	swap(b, size2, ben);
	ben->sb++;
	write(1, "sb\n", 3);
}

void	ss(t_data *meow, t_bench ben)
{
	swap(a, size1, ben);
	swap(b, size2, ben);
	ben->ss++;
	write(1, "ss\n", 3);
}
