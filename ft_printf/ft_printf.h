/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 01:29:33 by mavanesy          #+#    #+#             */
/*   Updated: 2026/03/20 20:40:17 by mavanesy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	ft_c_printf(char c);
int	ft_conversion(char s, va_list *box);
int	ft_u_printf(unsigned int n);
int	ft_p_printf(void *num);
int	ft_id_printf(int n);
int	ft_x_printf(unsigned long n, int X);
int	ft_s_printf(char *s);

#endif
