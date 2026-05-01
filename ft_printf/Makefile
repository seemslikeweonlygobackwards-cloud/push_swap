NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
       ft_conversion.c \
	   ft_id_printf.c \
	   ft_c_printf.c \
	   ft_p_printf.c \
	   ft_x_printf.c \
	   ft_u_printf.c \
	   ft_s_printf.c \

OBJS = $(SRCS:.c=.o)

AR = ar
ARFLAGS = rcs

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
