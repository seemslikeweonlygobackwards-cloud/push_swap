NAME = push_swap
LIBFT = libft/libft.a
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c push_swap.c merge_sort.c
OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
