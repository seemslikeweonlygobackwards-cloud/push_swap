/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_strategy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 19:24:39 by mavanesy          #+#    #+#             */
/*   Updated: 2026/05/02 16:44:51 by mavanesy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	start_index(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_strncmp(argv[i], "--bench", 7)
			|| !ft_strncmp(argv[i], "--simple", 8)
			|| !ft_strncmp(argv[i], "--medium", 8)
			|| !ft_strncmp(argv[i], "--complex", 9)
			|| !ft_strncmp(argv[i], "--adaptive", 10))
			i++;
		else
			break ;
	}
	return (i);
}

t_mode	parse_mode(int argc, char **argv, t_bench *ben)
{
	int		i;
	t_mode	mode;

	i = 1;
	mode = ADAPTIVE;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (!ft_strncmp(argv[i], "--bench", 7))
			ben->enabled = 1;
		else if (!ft_strncmp(argv[i], "--simple", 8))
			mode = SIMPLE;
		else if (!ft_strncmp(argv[i], "--medium", 8))
			mode = MEDIUM;
		else if (!ft_strncmp(argv[i], "--complex", 9))
			mode = COMPLEX;
		else if (!ft_strncmp(argv[i], "--adaptive", 10))
			mode = ADAPTIVE;
		else
			return (error(), ADAPTIVE);
		i++;
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

double	disorder_strategy(t_number *a, int *size1, t_bench *ben)
{
	double	disorder;

	disorder = compute_disorder(a, *size1);
	if (*size1 <= 3)
		simple_sort(a, size1, ben);
	else if (disorder < 0.2)
		simple_sort(a, size1, ben);
	else if (disorder < 0.5)
		medium_sort(a, size1, ben);
	else
		complex_sort(a, size1, ben);
	return (disorder);
}
