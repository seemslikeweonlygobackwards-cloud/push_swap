/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 15:01:22 by monika            #+#    #+#             */
/*   Updated: 2026/04/28 20:24:49 by mavanesy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	indexing(t_number *arr, int size)
{
	int	sort;
	int	i;
	int	j;

	i = 0;
	if (!arr || size <= 0)
		return (-1);
	while (i < size)
	{
		j = 0;
		sort = 0;
		while (j < size)
		{
			if (arr[j].value < arr[i].value)
				sort++;
			j++;
		}
		arr[i].index = sort;
		i++;
	}
	return (0);
}
