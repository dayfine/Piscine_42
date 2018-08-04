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
	char	matrix[SIZE][SIZE];
	int		num_cells_free;
	t_point	available_moves[NUM_CELLS +1];
}				t_board;

t_board		*create_board(char **rows);

void		destory_board(t_board *board);

void 		print_board(t_board *board);

#endif
