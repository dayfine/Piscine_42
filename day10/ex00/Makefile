CC=gcc
CFLAGS=-Wall -Wextra -Werror -g

NAME=libft.a

SRC_DIR=$(CURDIR)/srcs

SRC=$(SRC_DIR)/ft_putchar.c $(SRC_DIR)/ft_putstr.c $(SRC_DIR)/ft_strcmp.c \
	$(SRC_DIR)/ft_strlen.c $(SRC_DIR)/ft_swap.c

OBJS=ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

HEADERS=$(CURDIR)/includes/ft.h

all: $(NAME)

$(NAME):
	gcc -c $(CFLAGS) $(SRC) -I $(HEADERS)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
re: fclean all
