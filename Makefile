NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_outils.c

OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror 

CC = gcc

INDEX = ranlib

all: $(NAME)

$(NAME):
	$(CC) -c $(CFLAGS) $(SRCS)
	ar rc $(NAME) $(OBJ)
	$(INDEX) $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re