#include "ft_print_utils.h"
#include "ft_sudoku_board.h"

void	display_error(void)
{
	ft_putstr("Error\n");
}


int		main(int argc, char **argv)
{

	t_board *board;

	if (argc != 10)
	{
		display_error();
		return (1);
	}
	argv++;
	board = create_board(argv);
	print_board(board);
	destory_board(board)
	return (0);
}
