/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_strategy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 19:24:39 by mavanesy          #+#    #+#             */
/*   Updated: 2026/05/01 16:22:39 by mavanesy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_mode	parse_mode(int argc, char **argv)
{
	t_mode	mode;

	mode = ADAPTIVE;
	if (!ft_strcmp(argv[1], "--simple"))
		mode = SIMPLE;
	if (!ft_strcmp(argv[1], "--medium"))
		mode = MEDIUM;
	if (!ft_strcmp(argv[1], "--complex"))
		mode = COMPLEX;
	if (!ft_strcmp(argv[1], "--adaptive"))
		mode = ADAPTIVE;
	return (mode);
}

double	compute_disorder(t_number *a, int size)
{
	int		i;
	int		j;
	int		mistakes;
	int		total;

	if (size <= 1)
		return (0.0);
	mistakes = 0;
	total = size * (size - 1) / 2;
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (a[i].index > a[j].index)
				mistakes++;
			j++;
		}
		i++;
	}
	return ((double)mistakes / total);
}

void	disorder_strategy(t_number *a, int *size1)
{
	double	disorder;

	if (*size1 <= 3)
	{
		simple_sort(a, size1);
		return ;
	}
	disorder = compute_disorder(a, *size1);
	if (disorder < 0.2)
		simple_sort(a, size1);
	else if (disorder < 0.5)
		medium_sort(a, size1);
	else
		medium_sort(a, size1);
}