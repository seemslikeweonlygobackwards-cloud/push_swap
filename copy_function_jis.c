/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_function_jis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 20:21:03 by mavanesy          #+#    #+#             */
/*   Updated: 2026/04/28 22:38:58 by mavanesy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*step_copy(t_number *arr, int size)
{
	int	*copy;
	int	i;

	i = 0;
	copy = malloc(sizeof(int) * size);
	if (!copy)
		return (NULL);
	while (i < size)
	{
		copy[i] = arr[i].value;
		i++;
	}
	return (copy);
}
