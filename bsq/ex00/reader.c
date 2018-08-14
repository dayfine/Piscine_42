/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:11:48 by dfan              #+#    #+#             */
/*   Updated: 2018/08/13 16:33:36 by agauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft.h"

int		includes(char *str, char letter)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i++] == letter)
			return (1);
	}
	return (0);
}

int		ft_read_meta(int fd, char *symbols, int *row_count_ptr)
{
	char	buf[1];
	int		i;
	int		ret;

	*row_count_ptr = 0;
	i = 0;
	while ((ret = read(fd, buf, 1)))
	{
		if (!(buf[0] >= '0' && buf[0] <= '9'))
			break ;
		*row_count_ptr = *row_count_ptr * 10 + (buf[0] - '0');
	}
	if (buf[0] != '\n')
		symbols[i++] = buf[0];
	while ((ret = read(fd, buf, 1)))
	{
		if (buf[0] == '\n')
			break ;
		symbols[i++] = buf[0];
	}
	symbols[i] = '\0';
	return (!(i == 3 && *row_count_ptr > 0));
}

int		ft_read_first_line(int fd, char *symbols, char **m, int *col_count_ptr)
{
	char	buf[1];
	int		ret;
	t_list	**list_head;
	t_list	*curr;

	curr = NULL;
	list_head = &curr;
	*col_count_ptr = 0;
	while ((ret = read(fd, buf, 1)))
	{
		if (buf[0] == '\n')
			break ;
		if (!includes(symbols, buf[0]))
			return (1);
		*col_count_ptr += 1;
		ft_list_push_back(list_head, buf[0]);
	}
	if (!(*col_count_ptr))
		return (1);
	m[0] = ft_list_to_string(*list_head, *col_count_ptr);
	ft_list_clear(list_head);
	return (0);
}

int		ft_read_line(int fd, int idx, t_solution *s)
{
	char	buf[s->width + 1];
	char	*res;
	int		size;
	int		ret;
	int		i;

	size = s->width;
	ret = read(fd, buf, size + 1);
	if (ret != size + 1)
		return (1);
	res = malloc(sizeof(char) * (size + 1));
	i = -1;
	while (++i < size)
	{
		if (!includes(s->symbols, buf[0]))
			return (1);
		res[i] = buf[i];
	}
	if (buf[size] != '\n')
		return (1);
	res[size] = '\0';
	s->matrix[idx] = res;
	return (0);
}

void	ft_bsq_map_op(int fd)
{
	int			row_count;
	int			col_count;
	char		*symbols;
	char		**matrix;
	t_solution	*solution;

	symbols = malloc(sizeof(char) * 4);
	if (ft_read_meta(fd, symbols, &row_count))
		return (ft_maperr());
	matrix = (char**)malloc(sizeof(char*) * (row_count + 1));
	if (ft_read_first_line(fd, symbols, matrix, &col_count))
		return (ft_maperr());
	solution = create_solution(matrix, symbols, row_count, col_count);
	while (row_count-- > 1)
	{
		if (ft_read_line(fd, solution->height - row_count, solution))
		{
			destroy_board(solution);
			return (ft_maperr());
		}
	}
	find_bsq(solution);
	apply_solution(solution);
	print_board(solution);
	destroy_board(solution);
}
