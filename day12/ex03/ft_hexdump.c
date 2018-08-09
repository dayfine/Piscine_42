/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 14:51:57 by dfan              #+#    #+#             */
/*   Updated: 2018/08/08 14:51:57 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#include "ft_print_utils.h"

#define BUF_SIZE 16

int		ft_write(char *filename)
{
	int		fd;
	int		errno;
	long	ret;
	char	buf[BUF_SIZE + 1];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("hexdump: ");
		ft_putstr(filename);
		if (errno == ENOENT)
			ft_putstr(": No such file or directory\n");
		if (errno == EACCES)
			ft_putstr(": Permission denied\n");
		return (1);
	}
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		print_ascii(buf);
	}
	if (close(fd) == -1)
		return (1);
	return (0);
}

int		main(int argc, char *argv[])
{
	int		i;

	if (argc < 3)
		return (1);
	i = 1;
	while (++i < argc)
		ft_write(argv[i]);
	return (0);
}

