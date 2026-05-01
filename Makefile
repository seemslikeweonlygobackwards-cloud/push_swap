NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a
PRINTF = libftprintf/libftprintf.a

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
       sorted_arr.c 

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
