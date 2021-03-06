/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:11:51 by dfan              #+#    #+#             */
/*   Updated: 2018/08/13 11:11:52 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft.h"

t_solution	*create_solution(char **matrix, char *symbols, int h, int w)
{
	t_solution	*solution;
	int			i;

	solution = malloc(sizeof(t_solution));
	solution->symbols = symbols;
	solution->width = w;
	solution->height = h;
	solution->max_size = 0;
	solution->max_x = -1;
	solution->max_y = -1;
	solution->matrix = matrix;
	i = 0;
	while (++i < h)
		matrix[i] = NULL;
	return (solution);
}

void		destroy_board(t_solution *s)
{
	int i;

	i = -1;
	while (++i < s->height)
	{
		if (s->matrix[i] != NULL)
			free(s->matrix[i]);
	}
	free(s->matrix);
	free(s);
}

void		update_solution(t_solution *s, int size, int x, int y)
{
	s->max_size = size;
	s->max_x = x;
	s->max_y = y;
}

void		apply_solution(t_solution *s)
{
	int i;
	int j;

	if (s->max_size <= 0)
		return ;
	i = s->max_x + 1;
	while (--i > s->max_x - s->max_size)
	{
		j = s->max_y + 1;
		while (--j > s->max_y - s->max_size)
			s->matrix[i][j] = s->symbols[2];
	}
}

void		print_board(t_solution *s)
{
	int i;

	i = -1;
	while (++i < s->height)
	{
		ft_putstr(s->matrix[i]);
		ft_putchar('\n');
	}
}
