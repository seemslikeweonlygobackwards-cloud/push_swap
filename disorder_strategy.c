/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_strategy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 19:24:39 by mavanesy          #+#    #+#             */
/*   Updated: 2026/05/01 17:07:15 by mavanesy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	start_index(int argc, char **argv)
{
	if (argc > 1 && argv[1][0] == '-' && argv[1][1] == '-')
		return (2);
	return (1);
}

t_mode	parse_mode(int argc, char **argv)
{
	t_mode	mode;
	int		start;

	mode = ADAPTIVE;
	start = start_index(argc, argv);
	if (start == 2)
	{
		if (!ft_strncmp(argv[1], "--simple", 8))
			mode = SIMPLE;
		if (!ft_strncmp(argv[1], "--medium", 8))
			mode = MEDIUM;
		if (!ft_strncmp(argv[1], "--complex", 9))
			mode = COMPLEX;
		if (!ft_strncmp(argv[1], "--adaptive", 10))
			mode = ADAPTIVE;
	}
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

int	disorder_strategy(t_number *a, int *size1)
{
	double	disorder;

	if (*size1 <= 3)
	{
		simple_sort(a, size1);
		return ;
	}
	disorder = compute_disorder(a, *size1);
	if (disorder < 0.2)
		return (simple_sort(a, size1));
	else if (disorder < 0.5)
		return (medium_sort(a, size1));
	else
		return (medium_sort(a, size1));
}
