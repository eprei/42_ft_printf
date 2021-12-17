# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epresa-c <epresa-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/17 13:39:22 by epresa-c          #+#    #+#              #
#    Updated: 2021/12/17 15:15:19 by epresa-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_outils1.c ft_printf_outils2.c

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
