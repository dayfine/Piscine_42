# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dfan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/06 19:58:49 by dfan              #+#    #+#              #
#    Updated: 2018/08/06 19:58:55 by dfan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC=gcc
CFLAGS=-Wall -Wextra -Werror -g

NAME=do-op

OUT=do-op

all: $(NAME)

$(NAME):
	gcc -c *.c
	gcc *.o -o $(OUT)

clean:
	rm -f *.o

fclean: clean
	rm -f $(OUT)

re: fclean all
