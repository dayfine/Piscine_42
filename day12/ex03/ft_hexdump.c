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


#include "ft_print_utils.h"

#define BUF_SIZE 16

void	ft_write_from_stream(int fd)
{
	long	ret;
	long	addr;
	char	buf[BUF_SIZE + 1];

	addr = 0;
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		print_address(addr);
		print_hex(buf);
		print_ascii(buf);
		addr += ret;
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

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (handle_fd_errors("hexdump", filename));
	ft_write_from_stream(fd);
	if (close(fd) == -1)
		return (1);
	return (0);
}

int		main(int argc, char *argv[])
{
	int		i;

	if (argc <= 2)
		ft_write_from_stream(STDIN_FILENO);
	i = 1;
	while (++i < argc)
		ft_write_from_file(argv[i]);
	return (0);
}
