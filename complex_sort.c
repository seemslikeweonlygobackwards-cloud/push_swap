/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monika <monika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 20:21:50 by amghazar          #+#    #+#             */
/*   Updated: 2026/05/03 01:53:45 by monika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bits_number(int number)
{
	int	count;

	count = 0;
	while (number > 0)
	{
		number /= 2;
		count++;
	}
	return (count);
}

void	process_bit(t_data *meow, t_bench *ben, int bit)
{
	int	count;

	count = meow->size1;
	while (count--)
	{
		if (((meow->a[0].index >> bit) & 1) == 0)
			pb(meow, ben);
		else
			ra(meow, ben);
	}
	while (meow->size2 > 0)
		pa(meow, ben);
}

int	complex_sort(t_number *a, int *size1, t_bench *ben)
{
	t_data	meow;
	int		bit;
	int		max_bits;

	meow.a = a;
	meow.size1 = *size1;
	meow.size2 = 0;
	if (*size1 <= 100)
		return(medium_sort(a, size1, ben));
	meow.b = malloc(sizeof(t_number) * (*size1));
	if (!meow.b)
		return (free(a), error(), 1);
	max_bits = get_bits_number(*size1 - 1);
	bit = 0;
	while (bit < max_bits)
	{
    	if (sorted_arr(meow.a, meow.size1) && meow.size2 == 0)
        	break;
    	process_bit(&meow, ben, bit);
    	bit++;
	}
	free(meow.b);
	return (0);
}
