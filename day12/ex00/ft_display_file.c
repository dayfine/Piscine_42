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

#include "ft_file_op.h"
#include "ft_print_utils.h"

#define BUF_SIZE 4096

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
	return (ft_perform_file_op("cat", filename, ft_write_from_stream));
}

int		main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_puterr(argc == 1 ? "File name missing.\n" : "Too many arguments.\n");
		return (1);
	}
	ft_write_from_file(argv[1]);
	return (0);
}
