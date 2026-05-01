/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 19:31:03 by mavanesy          #+#    #+#             */
/*   Updated: 2026/03/20 20:25:19 by mavanesy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_x_printf(unsigned long n, int X)
{
	char	c;
	int		count;

	count = 0;
	if (n / 16 != 0)
		count = count + ft_x_printf(n / 16, X);
	if (n % 16 < 10)
		c = n % 16 + '0';
	else
	{
		if (X)
			c = n % 16 - 10 + 'A';
		else
			c = n % 16 - 10 + 'a';
	}
	write(1, &c, 1);
	return (count + 1);
}
