/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 19:19:48 by mavanesy          #+#    #+#             */
/*   Updated: 2026/03/20 20:13:35 by mavanesy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_u_printf(unsigned int n)
{
	char	c;
	int		count;

	count = 0;
	if (n / 10 != 0)
		count = count + ft_u_printf(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
	return (count + 1);
}
