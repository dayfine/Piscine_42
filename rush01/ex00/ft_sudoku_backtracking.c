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

#include <stdio.h>

#include "ft_sudoku_board.h"
#include "ft_get_candidates_utils.h"

typedef struct s_point	t_point;

typedef struct s_board	t_board;


void	make_move(int x, int y, char to_fill, t_board *board)
{
	fill_cell(x, y, to_fill, board);
}

void	unmake_move(int x, int y, t_board *board)
{
	free_cell(x, y, board);
}

// int		constructor_candidates(t_board *board)
// {

// }

int		backtrack(t_board *board)
{
	int		i;
	int		j;
	int		*possibles;
	int		best_len;
	int		*best;
	t_point	*best_point;

	printf("======working========\n");

	i = 0;
	j = 0;
	best_len = 9;
	while (i < SIZE)
	{
		while (j < SIZE)
		{
			if (board->matrix[i][j] != '.')
			{
				j++;
				continue;
			}
			possibles = get_possibles(i, j, board);
			if (get_possible_count(possibles) < best_len)
			{
				best_len = get_possible_count(possibles);
				best = possibles;
				best_point = create_point(i, j);
				if (best_len == 1)
					break;
			}
			j++;
		}
		i++;
	}

	if (best_len == 0 && board->num_cells_free == 0)
		return (1);
	i = 0;
	while (i < SIZE)
	{
		if (!best[i])
		{
			i++;
			continue;
		}
		make_move(best_point->x, best_point->y, get_value(best[i]), board);
		if (backtrack(board))
			return (1);
		unmake_move(best_point->x, best_point->y, board);
		i++;
	}
	return (0);
}
