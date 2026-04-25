/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monika <monika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 15:01:22 by monika            #+#    #+#             */
/*   Updated: 2026/04/25 18:42:38 by monika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int *step_copy(t_number *arr, int size)
{
    int *copy;
    int i;

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