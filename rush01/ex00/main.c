#include <stdlib.h>

#include "ft_sudoku_types.h"
#include "ft_print_utils.h"

void	display_error(void)
{
	ft_putstr("Error\n");
}




int		main(int argc, char **argv)
{
	int 	i;
	int		j;
	t_board	*board;

	if (argc != 10)
	{
		display_error();
		return (1)
	}
	board = malloc(t_board);
	i = 1;
	while (argv[i])
	{
		j = 0
		while (j < SIZE)
		{
			if (!argv[i][j])
			{
				display_error();
				return (1);
			}
			board->matrix[i][j] = argv[i][j];
			board->num_cells_free += argv[i][j] == '.';
		}
	}
	return (0);
}
