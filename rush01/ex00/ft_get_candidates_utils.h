#ifndef FT_GET_CANDIDATES_UTILS_H
# define FT_GET_CANDIDATES_UTILS_H

# include "ft_sudoku_board.h"



int		*make_possible_arr(void);

int		*get_possibles(int x, int y, t_board *board);

int		get_possible_count(int *possibles);

char	get_value(int n);

#endif
