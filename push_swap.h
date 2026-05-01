/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 23:08:42 by amghazar          #+#    #+#             */
/*   Updated: 2026/05/01 16:25:58 by mavanesy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct number
{
	int	value;
	int	index;
}	t_number;

typedef enum e_mode
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_mode;

int			duplicates(t_number *arr, int size);
int			first_handle(char *str);
long		error_handle(const char *str);
void		push(t_number *stack1, t_number *stack2, int *size1, int *size2);
void		pa(t_number *a, t_number *b, int *size1, int *size2);
void		pb(t_number *a, t_number *b, int *size1, int *size2);
void		rotate(t_number *stack, int size);
void		ra(t_number *a, int size1);
void		rb(t_number *b, int size2);
void		rr(t_number *a, t_number *b, int size1, int size2);
void		swap(t_number *stack, int size);
void		sa(t_number *a, int size1);
void		sb(t_number *b, int size2);
void		ss(t_number *a, t_number *b, int size1, int size2);
void		reverse_rotate(t_number *stack, int size);
void		rra(t_number *a, int size1);
void		rrb(t_number *b, int size2);
void		rrr(t_number *a, t_number *b, int size1, int size2);
void		free_everything(char **copy);
int			count_arg(int argc, char **argv);
int			fill_arr(t_number *s_arr, char **copy, int x);
t_number	*parse_arg(int argc, char **argv);
int			indexing(t_number *arr, int size);
double		compute_disorder(t_number *a, int size);
int			error(void);
int			preprocess(t_number *a, int size1);
void		decide_strategy(t_number *a, t_number *b, int *size1, int *size2);
int			chunk_up(int size);
void		push_chunks(t_number *a, t_number *b, int *size1, int *size2);
void		medium_sort(t_number *a, t_number *b, int *size1, int *size2);
void		sort2(t_number *a);
void		sort3(t_number *a);
void		find_min(t_number *a, t_number *b, int *size1, int *size2);
void		simple_sort(t_number *a, int *size1);
int			sorted_arr(t_number *a, int size1);

#endif