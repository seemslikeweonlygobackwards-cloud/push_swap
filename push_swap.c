/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 21:47:07 by mavanesy          #+#    #+#             */
/*   Updated: 2026/04/28 23:09:40 by mavanesy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(void)
{
	write(2, "Error\n", 6);
	return (1);
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
	if (!a)
		return (error());
	if (duplicates(a, size1))
		return (free(a), error());
	size2 = 0;
	b = malloc(sizeof(t_number) * size1);
	if (!b)
		return (free(a), error());
	indexing(a, size1);
	if (indexing(a, size1) == -1)
		return (free(a), free(b), error());
//	choose_strategy(a, b, &size_a, &size_b);
	free(a);
	free(b);
	return (0);
}
