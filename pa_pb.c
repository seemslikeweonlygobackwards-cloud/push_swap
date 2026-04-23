/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monika <monika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 19:52:02 by mavanesy          #+#    #+#             */
/*   Updated: 2026/04/23 22:40:16 by monika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_number *stack1, t_number *stack2, int *size1, int *size2)
{
	int	i;

	if (*size2 < 1)
		return ;
	i = *size1;
	while (i > 0)
	{
		stack1[i] = stack1[i - 1];
		i--;
	}
	stack1[0] = stack2[0];
	i = 0;
	while (i < *size2 - 1)
	{
		stack2[i] = stack2[i + 1];
		i++;
	}
	(*size2)--;
	(*size1)++;
}

void	pa(t_number *a, t_number *b, int *size1, int *size2)
{
	push(a, b, size1, size2);
	write(1, "pa\n", 3);
}

void	pb(t_number *a, t_number *b, int *size1, int *size2)
{
	push(b, a, size2, size1);
	write(1, "pa\n", 3);
}
