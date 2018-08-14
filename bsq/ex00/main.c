/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:11:42 by dfan              #+#    #+#             */
/*   Updated: 2018/08/13 16:29:58 by agauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft.h"

int main(int argc, char **argv)
{
	int		i;
	int		byte_read;
	char	buff[BUF_SIZE + 1];
	char	*board;

	i = 1;
	if (argc == 1)
	{
		while ((byte_read = read(0, buff, BUF_SIZE)))
		{
			buff[byte_read] = '\0';
			ft_putstr(buff);
		}
	}
	while (i < argc)
	{
		board = ft_read(argv[i]);
		check_size(board);
		printf("board :\n%s\n", board);
		printf("col :\n%d\n", (check_size(board)));
		ft_putchar('\n');
		i++;
	}
	return (0);
}
