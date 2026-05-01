NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

SRCS = main.c \
       indexing.c \
       duplicates.c \
       error_handle.c \
       pa_pb.c \
       sa_sb_ss.c \
       ra_rb_rr.c \
       rra_rrb_rrr.c \
       parse_arg.c \
       simple_sort.c \
       medium_sort.c \
       disorder_strategy.c \
       sorted_arr.c \
       complex_sort.c \
       ft_printf.c \
       print_bench.c \
       ft_conversion.c \
	ft_id_printf.c \
	ft_c_printf.c \
	ft_p_printf.c \
	ft_x_printf.c \
	ft_u_printf.c \
	ft_s_printf.c \
       print_counts.c

OBJS = $(SRCS:.c=.o)

RM = rm -f

all: $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C libft clean
	$(RM) $(OBJS)

fclean: clean
	make -C libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
