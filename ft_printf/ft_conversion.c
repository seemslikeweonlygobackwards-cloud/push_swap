/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 20:27:03 by mavanesy          #+#    #+#             */
/*   Updated: 2026/03/22 13:29:00 by mavanesy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion(char s, va_list *box)
{
	int	count;

	count = 0;
	if (!box)
		return (0);
	if (s == 'c')
		count = ft_c_printf (va_arg (*box, int));
	else if (s == 's')
		count = ft_s_printf (va_arg(*box, char *));
	else if (s == 'd' || s == 'i')
		count = ft_id_printf (va_arg(*box, int));
	else if (s == 'u')
		count = ft_u_printf (va_arg(*box, unsigned int));
	else if (s == 'x')
		count = ft_x_printf (va_arg(*box, unsigned int), 0);
	else if (s == 'X')
		count = ft_x_printf (va_arg(*box, unsigned int), 1);
	else if (s == 'p')
		count = ft_p_printf (va_arg(*box, void *));
	else if (s == '%')
		count = ft_c_printf ('%');
	return (count);
}
