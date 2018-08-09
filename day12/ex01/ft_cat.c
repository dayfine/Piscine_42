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

#include "ft_file_op.h"
#include "ft_print_utils.h"

#define BUF_SIZE 30

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
	int		i;

	i = 0;
	if (argc == 1)
		ft_write_from_stream(STDIN_FILENO);
	while (++i < argc)
		ft_write_from_file(argv[i]);
	return (0);
}
