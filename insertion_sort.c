/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monika <monika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 18:35:38 by monika            #+#    #+#             */
/*   Updated: 2026/04/26 22:04:29 by monika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort2(t_number *a)
{
    if(a[0].index > a[1].index)
        sa(a, 2);
    return ;
}

void sort3(t_number *a)
{
    if (a[0].index > a[1].index 
		&& a[1].index < a[2].index 
		&& a[0].index < a[2].index)
        sa(a, 3);
    else if (a[0].index > a[1].index && a[1].index > a[2].index)
    {
        sa(a, 3);
        rra(a, 3);
    }
    else if (a[0].index > a[1].index 
		&& a[1].index < a[2].index 
		&& a[0].index > a[2].index)
        ra(a, 3);
    else if (a[0].index < a[1].index 
		&& a[1].index > a[2].index 
		&& a[0].index < a[2].index)
    {
        sa(a, 3);
        ra(a, 3);
    }
    else if (a[0].index < a[1].index 
		&& a[1].index > a[2].index 
		&& a[0].index > a[2].index)
        rra(a, 3);
}

void    find_min(t_number *a, t_number *b, int *size1, int *size2)
{
    int min;
    int i;

    i = 0;
    min = 0;
    while (i < *size1)
    {
        if (a[i].index < a[min].index)
            min = i;
        i++;
    }
    if (min <= *size1 / 2)
        while (min-- > 0)
            ra(a, *size1);
    else
    {
        min = *size1 - min;
        while (min-- > 0)
            rra(a, *size1);
    }
    pb(a, b, size1, size2);
}

void	insertion_sort(t_number *a, t_number *b, int *size1, int *size2)
{
    int p;
 
	if (*size1 < 2)
		return ;
	if (*size1 == 2)
	{
        sort2(a);
		return ;
	}
	if (*size1 == 3)
	{
		sort3(a);
		return ;
	}
    p = *size1 - 3;
    while (p--)
        find_min(a, b, size1, size2);
    sort3(a);
    while (*size2 > 0)
        pa(a, b, size1, size2);
    return ;
}
