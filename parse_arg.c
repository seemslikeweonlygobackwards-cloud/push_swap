/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 17:43:57 by mavanesy          #+#    #+#             */
/*   Updated: 2026/04/20 15:24:58 by mavanesy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_arg(int argc, char **argv)
{
	char	**copy;
	int		i;
	int		j;
	int		count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		copy = ft_split(argv[i], ' ');
		if (!copy)
			return (-);
		j = 0;
		while (copy[j])
		{
			count++;
			free(copy[j]);
			j++;
		}
		i++;
		free(copy);
	}
	return (count);
}

int	*parse_arg(int argc, char **argv)
{
	int		*i_arr;
	int		i;
	char	**copy;
	int		count;

	i = 1;
	count = 0;
	copy = copy_arg(argc, *argv[i], count);
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
