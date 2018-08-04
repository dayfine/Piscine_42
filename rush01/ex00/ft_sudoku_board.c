#include <stdlib.h>

#include "ft_print_utils.h"

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
	t_point	available_moves[NUM_CELLS +1];
}				t_board;

t_board		*create_board(char **rows)
{
	int 	i;
	int		j;
	t_board	*board;
	board = malloc(sizeof(t_board));
	i = 0;
	while (rows[i])
	{
		j = 0;
		while (j < SIZE)
		{
			board->matrix[i][j] = rows[i][j];
			board->num_cells_free += rows[i][j] == '.';
			j++;
		}
		board->matrix[i][j] = 0;
		i++;
	}
	return (board);
}

void		destory_board(t_board *board)
{
	int i;

	i = 0;
	while (i < SIZE)
		free(board->matrix[i++]);
	free(board->matrix);

	free(board->available_moves);
	free(board);
}

void 		print_board(t_board *board)
{
	int i;

	i = 0;
	while (i < SIZE)
	{
		ft_putstr(board->matrix[i++]);
		ft_putchar('\n');
	}
}
