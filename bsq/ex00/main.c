/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:11:42 by dfan              #+#    #+#             */
/*   Updated: 2018/08/13 16:29:58 by agauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#include "ft.h"

int	handle_fd_errors(char *program, char *filename)
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

int	ft_perform_file_op(char *program, char *filename, t_file_op file_op)
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

int	main(int argc, char **argv)
{
	int		i;

	if (argc == 1)
		ft_bsq_map_op(STDIN_FILENO);
	i = 0;
	while (++i < argc)
	{
		ft_perform_file_op("bsq", argv[i], ft_bsq_map_op);
		if (argc > 2 && i != argc - 1)
			ft_putchar('\n');
	}
	return (0);
}
