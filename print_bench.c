/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 20:36:48 by mavanesy          #+#    #+#             */
/*   Updated: 2026/05/01 23:27:07 by mavanesy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	total_ops(t_bench *b)
{
	return (b->sa + b->sb + b->ss + b->pa + b->pb
		+ b->ra + b->rb + b->rr
		+ b->rra + b->rrb + b->rrr);
}

void	print_mode(t_mode mode)
{
	if (mode == SIMPLE)
		write(2, "Strategy: simple (O(n^2))\n", 26);
	else if (mode == MEDIUM)
		write(2, "Strategy: medium (O(nsqrt(n)))\n", 31);
	else if (mode == COMPLEX)
		write(2, "Strategy: complex (O(n log n))\n", 31);
	else
		write(2, "Strategy: adaptive\n", 19);
}

void	print_percent(double disorder)
{
	int	value;

	value = (int)(disorder * 10000);
	ft_putnbr_fd(value / 100, 2);
	write(2, ".", 1);
	if (value % 100 < 10)
		write(2, "0", 1);
	ft_putnbr_fd(value % 100, 2);
	write(2, "%\n", 2);
}

void	print_bench(t_bench *ben, double disorder, t_mode mode)
{
	if (!ben->enabled)
		return ;
	ft_putstr_fd("Disorder: ", 2);
	print_percent(disorder);
	print_mode(mode);
	ft_putstr_fd("Total ops: ", 2);
	ft_putnbr_fd(total_ops(ben), 2);
	ft_putstr_fd("\n", 2);
	print_counts(ben);
}
