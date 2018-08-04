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

#include "ft_sudoku_board.h"

int	*possibles(int x, int y, t_board *board);
{
	int i;
	int j;
	int *possibles;

	possibles = malloc(sizeof(int) * (SIZE + 1));
	i = 0
	while (i < SIZE)
	{
		if (board->matrix[i][y] != '.')
			possibles[board->matrix[i][y] - '1'] &= 0;
		if (board->matrix[x][i] != '.')
			possibles[board->matrix[x][i] - '1'] &= 0;
	}
	i = x / 3;
	j = y / 3;
	while (i < x / 3 + 3)
	{
		while (j < y / 3 + 3)
		{
			if (board->matrix[i][j] != '.')
				possibles[board->matrix[i][j] - '1'] &= 0;
		}
	}
	return (possibles);
}

char possible_value(int n)
{
	return ('1' + n);
}

void	make_move(char c)
{

}

void	unmake_move(char *str)
{

}

int		backtrack(t_board *board)
{

}
