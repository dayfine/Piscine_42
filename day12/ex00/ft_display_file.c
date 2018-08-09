/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 14:51:46 by dfan              #+#    #+#             */
/*   Updated: 2018/08/08 14:51:48 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 4096

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

int		handle_fd_errors(char *program, char *filename)
{
	ft_putstr(program);
	ft_putstr(": ");
	ft_putstr(filename);
	if (errno == ENOENT)
		ft_putstr(": No such file or directory\n");
	if (errno == EACCES)
		ft_putstr(": Permission denied\n");
	return (1);
}

int		ft_write_from_file(char *filename)
{
	int		fd;
	int		errno;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (handle_fd_errors("cat", filename));
	ft_write_from_stream(fd);
	if (close(fd) == -1)
		return (1);
	return (0);
}

int		main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_putstr(argc == 1 ? "File name missing.\n" : "Too many arguments.\n");
		return (1);
	}
	ft_write_from_file(argv[1]);
	return (0);
}
