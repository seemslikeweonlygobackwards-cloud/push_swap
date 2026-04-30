/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:08:32 by monika            #+#    #+#             */
/*   Updated: 2026/04/30 17:48:06 by mavanesy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted_arr(t_number *a, int size1)
{
	int	i;

	i = 0;
	while (i < size1 - 1)
	{
		if (a[i].index > a[i + 1].index)
			return (0);
		i++;
	}
	return (1);
}
