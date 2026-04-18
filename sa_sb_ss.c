/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 19:40:24 by mavanesy          #+#    #+#             */
/*   Updated: 2026/04/18 17:54:41 by mavanesy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *stack, int size)
{
	int	temp;

	if (size < 2)
		return ;
	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
}

void	sa(int *a, int size1)
{
	swap(a, size1);
	write(1, "sa\n", 3);
}

void	sb(int *b, int size2)
{
	swap(b, size2);
	write(1, "sb\n", 3);
}

void	ss(int *a, int *b, int size1, int size2)
{
	swap(a, size1);
	swap(b, size2);
	write(1, "ss\n", 3);
}
