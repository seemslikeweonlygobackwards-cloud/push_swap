/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 20:36:48 by mavanesy          #+#    #+#             */
/*   Updated: 2026/05/01 21:41:08 by mavanesy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_bench(t_bench *ben, double disorder, t_mode mode)
{
	if (!ben->enabled)
		return ;
	ft_dprintf(2, "Disorder: %.2f%%\n", disorder * 100.0);
	if (mode == SIMPLE)
		ft_dprintf(2, "Strategy: simple (O(n^2))\n");
	else if (mode == MEDIUM)
		ft_dprintf(2, "Strategy: medium (O(n√n))\n");
	else if (mode == COMPLEX)
		ft_dprintf(2, "Strategy: complex (O(n log n))\n");
	else
		ft_dprintf(2, "Strategy: adaptive\n");
	ft_dprintf(2, "Total ops: %d\n", total_ops(ben));
}
