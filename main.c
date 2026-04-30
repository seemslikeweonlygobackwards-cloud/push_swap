/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monika <monika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 21:47:07 by mavanesy          #+#    #+#             */
/*   Updated: 2026/04/29 22:54:11 by monika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	preprocess(t_number *a, int size1)
{
	if (duplicates(a, size1))
		return (free(a), 0);
	if (indexing(a, size1) == -1)
		return (free(a), 0);
	return (1);
}

void	decide_strategy(t_number *a, t_number *b, int *size1, int *size2)
{
	double  disorder;

	if (*size1 <= 3)
	{
		simple_sort(a, b, size1, size2);
		return ;
	}
	disorder = compute_disorder(a, *size1);
	if (disorder < 0.2)
	simple_sort(a, b, size1, size2);
	else if (disorder < 0.5)
		medium_sort(a, b, size1, size2);
	else
		complex_sort(a, b, size1, size2);
}

int	main(int argc, char **argv)
{
	t_number	*a;
	t_number	*b;
	int			size1;
	int			size2;

	if (argc < 2)
		return (0);
	size1 = count_arg(argc, argv);
	a = parse_arg(argc, argv);
	if (!a || !preprocess(a, size1))
		return (error());
	if (sorted_arr(a, size1))
		return (free(a), 0);
	size2 = 0;
	b = malloc(sizeof(t_number) * size1);
	if (!b)
		return (free(a), error());
	decide_strategy(a, b, &size1, &size2);
	free(a);
	free(b);
	return (0);
}
