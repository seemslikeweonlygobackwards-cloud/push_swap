/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monika <monika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 21:47:07 by mavanesy          #+#    #+#             */
/*   Updated: 2026/05/02 23:11:48 by monika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	return ;
}

int	preprocess(t_number *a, int size1)
{
	if (duplicates(a, size1))
		return (free(a), 0);
	if (indexing(a, size1) == -1)
		return (free(a), 0);
	return (1);
}

t_number	*init_data(int argc, char **argv, int *size1)
{
	t_number	*a;

	*size1 = count_arg(argc, argv);
	a = parse_arg(argc, argv);
	if (!a)
		return (error(), NULL);
	else if (!preprocess(a, *size1))
		return (error(), NULL);
	return (a);
}

void	run_sort(t_mode mode, t_number *a, int *size1, t_bench *ben)
{
	if (mode == SIMPLE)
		simple_sort(a, size1, ben);
	else if (mode == MEDIUM)
		medium_sort(a, size1, ben);
	else if (mode == COMPLEX)
		complex_sort(a, size1, ben);
	else
		disorder_strategy(a, size1, ben);
}

int	main(int argc, char **argv)
{
	t_number	*a;
	int			size1;
	t_mode		mode;
	t_bench		ben;
	double		disorder;

	if (argc < 2)
		return (0);
	ft_bzero(&ben, sizeof(ben));
	mode = parse_mode(argc, argv, &ben);
	if (!mode)
		return(error(), 0);
	a = init_data(argc, argv, &size1);
	if (!a)
		return (0);
	disorder = compute_disorder(a, size1);
	if (sorted_arr(a, size1))
		return (print_bench(&ben, disorder, mode), free(a), 0);
	run_sort(mode, a, &size1, &ben);
	free(a);
	return (print_bench(&ben, disorder, mode), 0);
}
