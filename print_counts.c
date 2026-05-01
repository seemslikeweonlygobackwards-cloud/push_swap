/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_counts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 23:19:33 by mavanesy          #+#    #+#             */
/*   Updated: 2026/05/01 23:23:49 by mavanesy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_line1(t_bench *ben)
{
	ft_putstr_fd("sa: ", 2);
	ft_putnbr_fd(ben->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(ben->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(ben->ss, 2);
	ft_putstr_fd("\n", 2);
}

void	print_line2(t_bench *ben)
{
	ft_putstr_fd("pa: ", 2);
	ft_putnbr_fd(ben->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(ben->pb, 2);
	ft_putstr_fd("\n", 2);
}

void	print_line3(t_bench *ben)
{
	ft_putstr_fd("ra: ", 2);
	ft_putnbr_fd(ben->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(ben->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(ben->rr, 2);
	ft_putstr_fd("\n", 2);
}

void	print_line4(t_bench *ben)
{
	ft_putstr_fd("rra: ", 2);
	ft_putnbr_fd(ben->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(ben->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(ben->rrr, 2);
	ft_putstr_fd("\n", 2);
}

void	print_counts(t_bench *ben)
{
	print_line1(ben);
	print_line2(ben);
	print_line3(ben);
	print_line4(ben);
}
