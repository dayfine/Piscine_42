#include <stdlib.h>
#include <stdio.h>
#include "test_utils.c"
#include "../ex00/solution.c"

int main(void)
{
	time_t t;

	srand(time(&t));

	char *symbols = ".ox";
	int m = 10;
	int n = 10;
	char **map;

	map = make_map(symbols, m, n, 10);
	print_matrix(map);
	solver(map, symbols, m, n);
	br();

	map = make_map(symbols, m, n, 10);
	print_matrix(map);
	solver(map, symbols, m, n);
	br();

	map = make_map(symbols, m, n, 10);
	print_matrix(map);
	solver(map, symbols, m, n);
	br();

	map = make_map(symbols, m, n, 10);
	print_matrix(map);
	solver(map, symbols, m, n);
	br();

	map = make_map(symbols, m, n, 10);
	print_matrix(map);
	solver(map, symbols, m, n);
	br();

	return (0);
}
