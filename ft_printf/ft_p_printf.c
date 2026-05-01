/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 20:16:28 by mavanesy          #+#    #+#             */
/*   Updated: 2026/03/20 21:09:00 by mavanesy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_p_printf(void *num)
{
	unsigned long	n;

	if (!num)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	n = (unsigned long)num;
	write (1, "0x", 2);
	return (2 + ft_x_printf(n, 0));
}
