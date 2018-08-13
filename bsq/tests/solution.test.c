#include <stdlib.h>
#include <stdio.h>
#include "test_utils.c"
#include "../ex00/solution.c"
#include "../ex00/find_bsq.c"

void	make_n_solve(char *symbols, int m, int n, int count)
{
	char **map;
	t_solution *solution;

	map = make_map(symbols, m, n, count);
	solution = create_solution(map, symbols, m, n);
	find_bsq(solution);
	apply_solution(solution);
	print_board(solution);
	destroy_board(solution);
	br();
}

int main(void)
{
	time_t t;

	srand(time(&t));

	char *symbols = ".ox";
	int m = 115;
	int n = 115;
	int count = 300;
	int test_count = 10;

	int i = 0;

	while (i++ < test_count)
		make_n_solve(symbols, m, n, count);
		make_n_solve(symbols, m, n, count);
		make_n_solve(symbols, m, n, count);
		make_n_solve(symbols, m, n, count);
		make_n_solve(symbols, m, n, count);

	return (0);
}
