# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/01 11:39:17 by lzimmerm          #+#    #+#              #
#    Updated: 2019/04/01 11:39:19 by lzimmerm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c \
	  srcs/ft_strlen.c srcs/ft_swap.c
OBJ = ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

HEADERS = includes

all: $(NAME)

$(NAME):
	gcc -c -I$(HEADERS) $(SRC)
	ar rc $(NAME) $(OBJ)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: clean all

