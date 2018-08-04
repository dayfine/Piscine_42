/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sudoku_board.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 09:34:18 by dfan              #+#    #+#             */
/*   Updated: 2018/08/04 09:34:19 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_sudoku_board.h"
#include "ft_print_utils.h"


# define SIZE 9
# define NUM_CELLS SIZE * SIZE

t_point		*create_point(int x, int y)
{
	t_point	*point;

	point = malloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	return (point);
}

t_board			*create_board(char **rows)
{
	int		i;
	int		j;
	t_board	*board;

	board = malloc(sizeof(t_board));
	i = 0;
	while (rows[i])
	{
		j = 0;
		while (j < SIZE)
		{
			board->matrix[i][j] = rows[i][j];
			board->num_cells_free += rows[i][j] == '.';
			j++;
		}
		board->matrix[i][j] = 0;
		i++;
	}
	return (board);
}

void			destory_board(t_board *board)
{
	int i;

	i = 0;
	while (i < SIZE)
		free(board->matrix[i++]);
	free(board->matrix);
	free(board->available_moves);
	free(board);
}

void			print_board(t_board *board)
{
	int i;

	i = 0;
	while (i < SIZE)
	{
		ft_putstr(board->matrix[i++]);
		ft_putchar('\n');
	}
}

void			fill_cell(int x, int y, char to_fill, t_board *board)
{
	board->matrix[x][y] = to_fill;
	board->num_cells_free -= 1;
}

void			free_cell(int x, int y, t_board *board)
{
	board->matrix[x][y] = '.';
	board->num_cells_free += 1;
}
