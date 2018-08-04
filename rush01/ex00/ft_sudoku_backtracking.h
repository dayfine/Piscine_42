/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sudoku_backtracking.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 09:34:12 by dfan              #+#    #+#             */
/*   Updated: 2018/08/04 09:34:14 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SUDOKU_BACKTRACKING_H
# define FT_SUDOKU_BACKTRACKING_H
# include "ft_sudoku_board.h"

int		*possibles(int x, int y, t_board *board);

char	possible_value(int n);

void	make_move(int x, int y, char to_fill, t_board *board);

void	unmake_move(int x, int y, t_board *board);

int		backtrack(t_board *board);

#endif
