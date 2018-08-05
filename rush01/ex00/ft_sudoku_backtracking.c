/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sudoku_backtracking.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 09:34:05 by dfan              #+#    #+#             */
/*   Updated: 2018/08/04 09:34:09 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_sudoku_board.h"
#include "ft_get_candidates_utils.h"

typedef struct s_point	t_point;

typedef struct s_board	t_board;

void		make_move(int x, int y, char to_fill, t_board *board)
{
	fill_cell(x, y, to_fill, board);
}

void		unmake_move(int x, int y, t_board *board)
{
	free_cell(x, y, board);
}

t_point		*find_best_point(t_board *board)
{
	int		i;
	int		j;
	int		best_len;
	int		count;
	t_point	*best_point;

	i = -1;
	best_point = NULL;
	best_len = 10;
	while (++i < SIZE)
	{
		j = -1;
		while (++j < SIZE)
		{
			if (board->matrix[i][j] != '.')
				continue;
			count = get_possible_count(get_possibles(i, j, board));
			if (count > 0 && count < best_len)
			{
				best_len = count;
				best_point = create_point(i, j);
			}
		}
	}
	return (best_point);
}

int			backtrack(t_board *board)
{
	int		i;
	int		*best;
	t_point	*best_point;

	if (board->num_cells_free == 0)
		return (1);
	best_point = find_best_point(board);
	if (!best_point)
		return (0);
	best = get_possibles(best_point->x, best_point->y, board);
	i = -1;
	while (++i < SIZE)
	{
		if (best[i] > 0)
		{
			make_move(best_point->x, best_point->y, get_value(i), board);
			if (backtrack(board))
				return (1);
			unmake_move(best_point->x, best_point->y, board);
		}
	}
	free(best_point);
	return (0);
}
