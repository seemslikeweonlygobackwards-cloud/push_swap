/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 17:43:57 by mavanesy          #+#    #+#             */
/*   Updated: 2026/05/02 16:59:54 by mavanesy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_everything(char **copy)
{
	int	i;

	i = 0;
	while (copy[i])
	{
		free(copy[i]);
		i++;
	}
	free(copy);
}

int	count_arg(int argc, char **argv)
{
	char	**copy;
	int		i;
	int		j;
	int		count;

	i = start_index(argc, argv);
	count = 0;
	while (i < argc)
	{
		copy = ft_split(argv[i], ' ');
		if (!copy)
			return (-1);
		j = 0;
		while (copy[j])
		{
			if (copy[j][0] != '\0')
				count++;
			free(copy[j]);
			j++;
		}
		free(copy);
		i++;
	}
	return (count);
}

int	fill_arr(t_number *s_arr, char **copy, int x)
{
	int		j;
	long	n;

	j = 0;
	while (copy[j])
	{
		if (copy[j][0] != '\0')
		{
			if (!first_handle(copy[j]))
				return (free(copy), -1);
			n = atoi_hand(copy[j]);
			if (n > 2147483647 || n < -2147483648)
				return (free_everything(copy), -1);
			s_arr[x].value = (int)n;
			s_arr[x].index = 0;
			x++;
		}
		free(copy[j]);
		j++;
	}
	return (free(copy), x);
}

t_number	*parse_arg(int argc, char **argv)
{
	t_number	*s_arr;
	int			i;
	char		**copy;
	int			count;
	int			x;

	i = start_index(argc, argv);
	x = 0;
	count = count_arg(argc, argv);
	if (count <= 0)
		return (NULL);
	s_arr = malloc(sizeof(t_number) * count);
	if (!s_arr)
		return (NULL);
	while (i < argc)
	{
		copy = ft_split(argv[i], ' ');
		if (!copy)
			return (free(s_arr), NULL);
		x = fill_arr(s_arr, copy, x);
		if (x == -1)
			return (free(s_arr), NULL);
		i++;
	}
	return (s_arr);
}
