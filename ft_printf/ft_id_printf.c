/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_id_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 21:51:39 by mavanesy          #+#    #+#             */
/*   Updated: 2026/03/20 20:11:59 by mavanesy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_id_printf(int n)
{
	char	c;
	int		count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		return (1 + ft_id_printf(-n));
	}
	if (n / 10 != 0)
		count = count + ft_id_printf(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
	return (count + 1);
}
