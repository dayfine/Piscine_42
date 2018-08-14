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
#include <stdio.h>

#include "ft.h"

t_solution	*create_solution(char **matrix, char *symbols, int w, int h)
{
	t_solution *solution;

	solution = malloc(sizeof(t_solution));
	solution->matrix = matrix;
	solution->symbols = symbols;
	solution->width = w;
	solution->height = h;
	solution->max_size = 0;
	solution->max_x = -1;
	solution->max_y = -1;
	return (solution);
}

void		destroy_board(t_solution *s)
{
	int i;

	i = -1;
	while (++i < s->height)
		free(s->matrix[i]);
	free(s->matrix);
	free(s);
}

void		update_solution(t_solution *s, int size, int x, int y)
{
	if (size > s->max_size)
	{
		s->max_size = size;
		s->max_x = x;
		s->max_y = y;
	}
}

void		apply_solution(t_solution *s)
{
	int i;
	int j;

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
	int j;

	i = -1;
	while (++i < s->height)
	{
		j = -1;
		while (++j < s->width)
			putchar(s->matrix[i][j]);
		putchar('\n');
	}
}
