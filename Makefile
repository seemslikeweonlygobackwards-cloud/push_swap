NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c \

OBJS = $(SRCS:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) libft/libft.a
	$(CC) $(OBJS) libft/libft.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libft/libft.a:
	make -C libft

clean:
	$(RM) $(OBJS)
	make -C libft clean

fclean: clean
	$(RM) $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
