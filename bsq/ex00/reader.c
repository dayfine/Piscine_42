/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:11:48 by dfan              #+#    #+#             */
/*   Updated: 2018/08/13 16:12:06 by agauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft.h"

long	get_file_size(char *filename)
{
	int		fd;
	long	ret;
	long	len;
	char	buf[BUF_SIZE + 1];

	fd = open(filename, O_RDONLY);
	len = 0;
	while ((ret = read(fd, buf, BUF_SIZE)))
		len += ret;
	close(fd);
	return (len);
}

int			check_size(char *str)
{
	int		row;
	int		col;
	int		i;
	int		nb;

	i = 0;
	row = 0;
	col = 0;
	nb = ft_atoi(str);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			row++;
		if (str[i] != '\n')
			col++;
		i++;
	}
	printf("str %s\n", str);
	printf("row %d \n", row);
	printf("col %d \n", col);
	if ((row -1) == col)
		return (col);
	return (-1);
}
char	*ft_read(char *filename)
{
	int		fd;
	int		i;
	int		byte_read;
	char	buff[BUFF_SIZE + 1];
	char	*board;
	int		j;

	i = 0;
	len = get_file_size(*filename);
	board = (char *)malloc(sizeof(char) * len);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() error.");
		return ("bad");
	}
	while ((byte_read = read(fd, buff, BUFF_SIZE)))
	{
		j = 0;
		while (j < byte_read)
			board[i++] = buff[j++];
	}
	board[i] = '\0';
	if (close(fd) == -1)
		ft_putstr("close() error.");
	return (board);
}


int			main(int argc, char **argv)
{
	int		i;
	int		byte_read;
	char	buff[BUFF_SIZE + 1];
	char	*board;

	i = 1;
	if (argc == 1)
	{
		while ((byte_read = read(0, buff, BUFF_SIZE)))
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
