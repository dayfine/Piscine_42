CFLAGS=-Wall -Wextra -Werror -g

NAME=ft_last

all: $(NAME)

$(NAME):
	gcc -c $(CFLAGS) *.c
	gcc *.o -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm $(NAME)

re: fclean all
