# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agauthie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/13 11:20:53 by agauthie          #+#    #+#              #
#    Updated: 2018/08/13 16:14:12 by agauthie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SOURCES = reader.c ft_utils.c
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
