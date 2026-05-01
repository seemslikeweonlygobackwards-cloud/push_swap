/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 19:52:02 by mavanesy          #+#    #+#             */
/*   Updated: 2026/05/01 22:22:07 by mavanesy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_data *meow)
{
	int	i;

	if (meow->size2 < 1)
		return ;
	i = meow->size1;
	while (i > 0)
	{
		meow->a[i] = meow->a[i - 1];
		i--;
	}
	meow->a[0] = meow->b[0];
	i = 0;
	while (i < meow->size2 - 1)
	{
		meow->b[i] = meow->b[i + 1];
		i++;
	}
	meow->size2--;
	meow->size1++;
}

void	pa(t_data *meow, t_bench *ben)
{
	push(meow);
	ben->pa++;
	write(1, "pa\n", 3);
}

void	pb(t_data *meow, t_bench *ben)
{
	int	i;

	if (meow->size1 < 1)
		return ;
	i = meow->size2;
	while (i > 0)
	{
		meow->b[i] = meow->b[i - 1];
		i--;
	}
	meow->b[0] = meow->a[0];
	i = 0;
	while (i < meow->size1 - 1)
	{
		meow->a[i] = meow->a[i + 1];
		i++;
	}
	meow->size1--;
	meow->size2++;
	ben->pb++;
	write(1, "pb\n", 3);
}
