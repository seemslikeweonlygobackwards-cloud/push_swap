/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 17:05:59 by amghazar          #+#    #+#             */
/*   Updated: 2026/04/15 18:27:31 by mavanesy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*merge(int **array1, int **array2, int size1, int size2)
{
	int	*sorted_array;
	int	i;
	int	j;
	int	k;

	sorted_array = malloc(sizeof(int) * (size1 + size2));
	i = 0;
	j = 0;
	k = 0;
	while (i < size1 && j < size2)
	{
		if ((*array1)[i] > (*array2)[j])
		{
			sorted_array[k] = (*array2)[j];
			j++;
		}
		else
		{
			sorted_array[k] = (*array1)[i];
			i++;
		}
		k++;
	}
	while (i < size1)
	{
		sorted_array[k] = (*array1)[i];
		i++;
		k++;
	}
	while (j < size2)
	{
		sorted_array[k] = (*array2)[j];
		j++;
		k++;
	}

	free(*array1);
	free(*array2);
	return (sorted_array);
}

int	*merge_sort(int **array, int size)
{
	int	half_size;
	int	*array1;
	int	*array2;
	int	i;
	int	j;

	if (size == 1)
	{
		// free(*array1);
		// free(*array2);
		return (*array);
	}
	if (size % 2 == 0)
		half_size = size / 2;
	else
		half_size = size / 2 + 1;
	array1 = malloc(sizeof(int) * (half_size));
	array2 = malloc(sizeof(int) * size / 2);
	i = 0;
	while (i < half_size)
	{
		array1[i] = (*array)[i];
		i++;
	}
	j = 0;
	while (j < size / 2)
	{
		array2[j] = (*array)[i];
		i++;
		j++;
	}
	array1 = merge_sort(&array1, half_size);
	array2 = merge_sort(&array2, size / 2);
	i = 0;
	// while (i < half_size)
	// {
	// 	printf(" %d ", array1[i]);
	// 	i++;
	// }
	return (merge(&array1, &array2, half_size, size / 2));
}
