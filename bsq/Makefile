# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agauthie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/13 11:20:53 by agauthie          #+#    #+#              #
#    Updated: 2018/08/13 16:17:54 by agauthie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SOURCES = $(wildcard src/*.c)
HEADER = src/ft.h
OBJECTS=$(patsubst %.c, %.o, $(SOURCES))
FLAGS = -Wall -Wextra -Werror

all:
	gcc $(FLAGS) $(SOURCES) -I $(HEADER) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
