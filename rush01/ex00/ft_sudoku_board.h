/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sudoku_board.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 09:34:22 by dfan              #+#    #+#             */
/*   Updated: 2018/08/04 09:34:23 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SUDOKU_BOARD_H
# define FT_SUDOKU_BOARD_H

# define SIZE 9
# define NUM_CELLS SIZE * SIZE

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_board
{
	char	matrix[SIZE + 1][SIZE + 1];
	int		num_cells_free;
	t_point	available_moves[NUM_CELLS + 1];
}				t_board;

t_point		*create_point(int x, int y);

t_board		*create_board(char **rows);

void		destory_board(t_board *board);

void 		print_board(t_board *board);

void		fill_cell(int x, int y, char to_fill, t_board *board);

void		free_cell(int x, int y, t_board *board);

#endif
