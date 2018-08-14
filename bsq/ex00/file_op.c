/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:11:38 by dfan              #+#    #+#             */
/*   Updated: 2018/08/13 11:11:41 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#include "ft.h"

int			handle_fd_errors(char *program, char *filename)
{
	ft_puterr(program);
	ft_puterr(": ");
	ft_puterr(filename);
	if (errno == ENOENT)
		ft_puterr(": No such file or directory\n");
	if (errno == EACCES)
		ft_puterr(": Permission denied\n");
	return (1);
}

int			ft_perform_file_op(char *program, char *filename, t_file_op file_op)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (handle_fd_errors(program, filename));
	file_op(fd);
	if (close(fd) == -1)
		return (1);
	return (0);
}
