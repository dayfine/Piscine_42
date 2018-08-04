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

typedef struct s_point	t_point;

typedef struct s_board	t_board;

t_board		*create_board(char **rows);

void		destory_board(t_board *board);

void 		print_board(t_board *board);

void		fill_cell(int x, int y, char to_fill, t_board *board);

void		free_cell(int x, int y, t_board *board);

#endif
