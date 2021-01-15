SRCS = ft_printf.c \
	   utils.c \
	   format_checker.c
OBJS = $(SRCS:.c=.o)
HEADER = libft.h
NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I $(HEADER)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONEY: all clean fclean
