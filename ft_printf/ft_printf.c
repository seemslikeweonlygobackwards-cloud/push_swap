/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 21:20:54 by mavanesy          #+#    #+#             */
/*   Updated: 2026/03/20 20:46:14 by mavanesy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	box;
	int		count;

	count = 0;
	va_start(box, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (!*s)
			{
				va_end(box);
				return (count);
			}
			count = count + ft_conversion(*s, &box);
		}
		else
			count = count + write(1, s, 1);
		s++;
	}
	va_end(box);
	return (count);
}
