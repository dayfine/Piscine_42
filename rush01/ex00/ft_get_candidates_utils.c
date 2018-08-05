/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_candidates_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 14:37:31 by dfan              #+#    #+#             */
/*   Updated: 2018/08/04 14:37:33 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_sudoku_board.h"

typedef struct s_point	t_point;

typedef struct s_board	t_board;

int		*make_possible_arr(void)
{
	int i;
	int *possibles;

	possibles = malloc(sizeof(int) * (SIZE + 1));
	i = 0;
	while (i < SIZE)
		possibles[i++] = 1;
	return (possibles);
}

int		*get_possibles(int x, int y, t_board *board)
{
	int i;
	int j;
	int *possibles;

	possibles = make_possible_arr();
	i = -1;
	while (++i < SIZE)
	{
		if (board->matrix[i][y] != '.')
			possibles[board->matrix[i][y] - '1'] &= 0;
		if (board->matrix[x][i] != '.')
			possibles[board->matrix[x][i] - '1'] &= 0;
	}
	i = x / 3 * 3 - 1;
	while (++i < (x / 3 * 3 + 3))
	{
		j = y / 3 * 3 - 1;
		while (++j < (y / 3 * 3 + 3))
		{
			if (board->matrix[i][j] != '.')
				possibles[board->matrix[i][j] - '1'] &= 0;
		}
	}
	return (possibles);
}

int		get_possible_count(int *possibles)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < SIZE)
		count += possibles[i++];
	return (count);
}

char	get_value(int n)
{
	return ('1' + n);
}
