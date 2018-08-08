/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 14:51:51 by dfan              #+#    #+#             */
/*   Updated: 2018/08/08 14:51:52 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

#define BUF_SIZE 30

void	ft_putstr(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
}

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

int		ft_write_from_file(char *filename)
{
	int		fd;
	int		errno;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("cat: ");
		ft_putstr(filename);
		if (errno == ENOENT)
			ft_putstr(": No such file or directory\n");
		if (errno == EACCES)
			ft_putstr(": Permission denied\n");
		return (1);
	}
	ft_write_from_stream(fd);
	if (close(fd) == -1)
		return (1);
	return (0);
}

int		main(int argc, char *argv[])
{
	int		i;

	if (argc == 1)
	{
		ft_write_from_stream(STDIN_FILENO);
		return (1);
	}
	i = 0;
	while (++i < argc)
		ft_write_from_file(argv[i]);
	return (0);
}
