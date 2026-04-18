/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 23:06:03 by amghazar          #+#    #+#             */
/*   Updated: 2026/04/18 17:35:45 by mavanesy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"
#include "push_swap.h"
#include "merge_sort.h"

int	main(int argc, char **argv)
{
	int	*a;
	int	*a_copy;
	int i;
	int j;

	a = malloc(sizeof(int) * (argc - 1));
	a_copy = malloc(sizeof(int) * (argc - 1));
	i = 1;
	j = 0;
	while (i < argc)
	{
		a[j] = ft_atoi(argv[i]);
		printf("%d ", a[j]);
		j++;
		i++;
	}
	i = 0;
	while (i < argc - 1)
	{
		a_copy[i] = a[i];
		i++;
	}

	i = 0;
	while (i < argc - 1)
	{
		printf("\n%d ", (merge_sort(&a_copy, argc - 1))[i]);
		i++;
	}
	free(a);
	free(a_copy);
}

/*


	// rotate(&a, argc - 1);
	// reverse_rotate(&a, argc - 1);
	// merge_sort(&a_copy, argc - 1);

get stack a as int *arr
hasError() -> not integers, integers outside the valid range, or duplicate values
	
1 3 2 7 15 10 4

size / 2 * pb -> [4, 10, 15] -> b stack | [1, 3, 2, 7] -> a stack
if size > 1 -> repeat



*/
