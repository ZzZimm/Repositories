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
