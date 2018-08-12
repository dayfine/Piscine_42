CC=gcc
CFLAGS=-Wall -Wextra -Werror -g

NAME=test.out

SRC=test.c

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all
