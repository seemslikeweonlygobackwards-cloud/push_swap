/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 21:47:07 by mavanesy          #+#    #+#             */
/*   Updated: 2026/04/30 20:27:48 by mavanesy         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_number	*a;
	int			size1;
	t_mode		mode;

	if (argc < 2)
		return (0);
	size1 = count_arg(argc, argv);
	a = parse_arg(argc, argv);
	if (!a || !preprocess(a, size1))
		return (error());
	if (sorted_arr(a, size1))
		return (free(a), 0);
	mode = parse_mode(argc, argv);
	if (mode == SIMPLE)
		simple_sort(a, &size1);
	else if (mode == MEDIUM)
		medium_sort(a, &size1);
	else if (mode == COMPLEX)
		medium_sort(a, &size1);
	else
		disorder_strategy(a, &size1);
	return (free(a), 0);
}
