/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monika <monika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 23:08:42 by amghazar          #+#    #+#             */
/*   Updated: 2026/05/02 23:06:03 by monika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "stdarg.h"

typedef struct s_number
{
	int	value;
	int	index;
}	t_number;

typedef struct s_data
{
	t_number	*a;
	t_number	*b;
	int			size1;
	int			size2;
}	t_data;

typedef enum e_mode
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_mode;

typedef struct s_bench
{
	int	enabled;
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_bench;

int			duplicates(t_number *arr, int size);
int			first_handle(char *str);
long		atoi_hand(const char *str);
void		push(t_data *meow);
void		pa(t_data *meow, t_bench *ben);
void		pb(t_data *meow, t_bench *ben);
void		rotate(t_number *stack, int size);
void		ra(t_data *meow, t_bench *ben);
void		rb(t_data *meow, t_bench *ben);
void		rr(t_data *meow, t_bench *ben);
void		swap(t_number *stack, int size);
void		sa(t_data *meow, t_bench *ben);
void		sb(t_data *meow, t_bench *ben);
void		ss(t_data *meow, t_bench *ben);
void		reverse_rotate(t_number *stack, int size);
void		rra(t_data *meow, t_bench *ben);
void		rrb(t_data *meow, t_bench *ben);
void		rrr(t_data *meow, t_bench *ben);
void		free_everything(char **copy);
int			count_arg(int argc, char **argv);
int			fill_arr(t_number *s_arr, char **copy, int x);
t_number	*parse_arg(int argc, char **argv);
int			indexing(t_number *arr, int size);
double		compute_disorder(t_number *a, int size);
void		error(void);
int			preprocess(t_number *a, int size1);
t_number	*init_data(int argc, char **argv, int *size1);
double		disorder_strategy(t_number *a, int *size1, t_bench *ben);
void		run_sort(t_mode mode, t_number *a, int *size1, t_bench *ben);
int			chunk_up(int size);
void		push_chunks(t_data *meow, t_bench *ben);
int			medium_sort(t_number *a, int *size1, t_bench *ben);
void		helper(t_data *meow, t_bench *ben);
void		sort2(t_data *meow, t_bench *ben);
void		sort3(t_data *meow, t_bench *ben);
void		find_min(t_data *meow, t_bench *ben);
int			small_cases(t_data *meow, t_bench *ben);
int			simple_sort(t_number *a, int *size1, t_bench *ben);
int			sorted_arr(t_number *a, int size1);
int			start_index(int argc, char **argv);
t_mode		parse_mode(int argc, char **argv, t_bench *ben);
int			total_ops(t_bench *b);
void		print_bench(t_bench *ben, double disorder, t_mode mode);
int			get_bits_number(int number);
void		process_bit(t_data *meow, t_bench *ben, int bit);
int			complex_sort(t_number *a, int *size1, t_bench *ben);
void		print_mode(t_mode mode, double disorder);
void		print_line1(t_bench *ben);
void		print_line2(t_bench *ben);
void		print_line3(t_bench *ben);
void		print_line4(t_bench *ben);
void		print_counts(t_bench *ben);

#endif