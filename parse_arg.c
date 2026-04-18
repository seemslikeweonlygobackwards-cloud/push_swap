/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 17:43:57 by mavanesy          #+#    #+#             */
/*   Updated: 2026/04/18 19:07:17 by mavanesy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*parse_arg(int argc, char **argv)
{
	int		*i_arr;
	int		i;
	int		count;
	char	**copy;

	i = 1;
	count = 0;
	while (i < argc)
	{
		copy = ft_split(argv[i], ' ');
		i++;
		while (copy[count])
			count++;
	}
	i_arr = malloc(sizeof(int) * count);
	if (!i_arr)
		return (NULL);
	while (i < argc)
	{
		i_arr[i - 1] = ft_atoi(copy);
		i++;
	}
	return (i_arr);
}
