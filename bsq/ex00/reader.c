/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:11:48 by dfan              #+#    #+#             */
/*   Updated: 2018/08/13 16:33:36 by agauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft.h"

int		ft_read_meta(int fd, char *symbols, int *row_count_ptr)
{
	char	buf[1];
	int		i;
	int		ret;

	*row_count_ptr = 0;
	i = 0;
	while ((ret = read(fd, buf, 1)))
	{
		if (!(buf[0] >= '0' && buf[0] <= '9'))
			break ;
		*row_count_ptr = *row_count_ptr * 10 + (buf[0] - '0');
	}
	symbols[i++] = buf[0];
	while ((ret = read(fd, buf, 1)))
	{
		if (buf[0] == '\n')
			break ;
		symbols[i++] = buf[0];
	}
	symbols[i] = '\0';
	return (i == 3);
}

char	*ft_write_from_stream(int fd, long size)
{
	int		ret;
	char	buf[BUF_SIZE + 1];
	char	*res;
	int		i;
	int		j;

	res = malloc(sizeof(char) * (size + 1));
	i = 0;
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		j = 0;
		while (j < ret)
			res[i++] = buf[j++];
	}
	res[size] = '\0';
	return (res);
}

void	ft_read(int fd)
{
	int		row_count;
	char	*symbols;
	int		op_status;

	symbols = malloc(sizeof(char) * 4);
	op_status = ft_read_meta(fd, symbols, &row_count);
	printf("row: %d; symbols: '%s'\n", row_count, symbols);
}
