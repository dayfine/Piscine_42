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
#include <stdlib.h>
#include <stdio.h>

#include "ft_print_utils.h"
#include "ft_file_op.h"
#include "ft_hexdump_utils.h"
#include "ft_str_utils.h"

#define BUF_SIZE 16

void	ft_write_from_stream(int fd)
{
	long	ret;
	long	addr;
	char	buf[BUF_SIZE + 1];
	char	*last;
	int		repeat_printed;

	last = NULL;
	addr = 0;
	repeat_printed = 0;
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		hexdump_line(addr, buf, ft_strcmp(buf, last), &repeat_printed);
		last = ft_strdup(buf);
		addr += ret;
	}
	print_address(addr);
	ft_putstr("\n");
}

int		ft_write_from_file(char *filename)
{
	return (ft_perform_file_op("hexdump", filename, ft_write_from_stream));
}

int		main(int argc, char *argv[])
{
	int		i;

	i = 1;
	if (argc <= 2)
		ft_write_from_stream(STDIN_FILENO);
	while (++i < argc)
		ft_write_from_file(argv[i]);
	return (0);
}
