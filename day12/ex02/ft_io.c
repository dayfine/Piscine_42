/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 20:27:30 by dfan              #+#    #+#             */
/*   Updated: 2018/08/08 20:27:31 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

#include "ft_utils.h"

#define BUF_SIZE 8192

void	ft_write_from_stream(int fd)
{
	int		ret;
	char	buf[BUF_SIZE + 1];

	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		ft_putstr(buf);
	}
}

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

void	ft_write_from_stream_from_target(int fd, long target, \
										int print_header, char *filename)
{
	long	ret;
	long	loc;
	char	buf[BUF_SIZE + 1];

	loc = 0;
	while (loc < target - BUF_SIZE)
		loc += read(fd, buf, BUF_SIZE);
	read(fd, buf, target - loc);
	if (print_header)
	{
		ft_putstr("==> ");
		ft_putstr(filename);
		ft_putstr(" <==\n");
	}
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		ft_putstr(buf);
	}
}

int		ft_write_from_file_w_offset(char *filename, long offset, \
									int print_header)
{
	int		fd;
	int		errno;
	long	target;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("tail: ");
		ft_putstr(filename);
		if (errno == ENOENT)
			ft_putstr(": No such file or directory\n");
		if (errno == EACCES)
			ft_putstr(": Permission denied\n");
		return (1);
	}
	target = offset > 0 ? offset - 1 : get_file_size(filename) + offset;
	ft_write_from_stream_from_target(fd, target, print_header, filename);
	if (close(fd) == -1)
		return (1);
	return (0);
}
