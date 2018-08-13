# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agauthie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/13 11:20:53 by agauthie          #+#    #+#              #
#    Updated: 2018/08/13 15:23:49 by agauthie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SOURCES = reader.c ft_putchar.c ft_putstr.c ft_atoi.c
HEADER = ft.h
FLAGS = -Wall -Wextra -Werror
OUTPUT = *.o

all:
	gcc $(FLAGS) $(SOURCES) -I $(HEADER) -o $(NAME)

clean:
	rm -f $(OUTPUT)

fclean : clean
	rm -f $(NAME)

re : fclean all
