#ifndef FT_SUDOKU_BOARD_H
# define FT_SUDOKU_BOARD_H

typedef struct	s_point t_point;

typedef struct	s_board t_board;

t_board		*create_board(char **rows);

void		destory_board(t_board *board);

void 		print_board(t_board *board);

#endif
