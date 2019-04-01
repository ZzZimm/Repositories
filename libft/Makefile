# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/01 14:30:26 by lzimmerm          #+#    #+#              #
#    Updated: 2019/04/01 14:30:27 by lzimmerm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS=-Werror -Wall -Wextra

NAME=libft.a

SRC=./*.c

HEADERS=libft.h

OBJ=./*.o

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -c -I$(HEADERS) $(SRC)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
