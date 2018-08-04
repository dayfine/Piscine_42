/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_candidates_utils.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 14:37:21 by dfan              #+#    #+#             */
/*   Updated: 2018/08/04 14:37:25 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_CANDIDATES_UTILS_H
# define FT_GET_CANDIDATES_UTILS_H
# include "ft_sudoku_board.h"

int		*make_possible_arr(void);

int		*get_possibles(int x, int y, t_board *board);

int		get_possible_count(int *possibles);

char	get_value(int n);

#endif
