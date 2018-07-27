#include <stdio.h>
#include <assert.h>

#include "./ex00/ft_iterative_factorial.c"
#include "./ex01/ft_recursive_factorial.c"
#include "./ex02/ft_iterative_power.c"
#include "./ex03/ft_recursive_power.c"
#include "./ex04/ft_fibonacci.c"
#include "./ex05/ft_sqrt.c"
#include "./ex06/ft_is_prime.c"
#include "./ex07/ft_find_next_prime.c"
#include "./ex08/ft_eight_queens_puzzle.c"
#include "./ex09/ft_eight_queens_puzzle_2.c"


int   main(void)
{
	printf("%s\n", "==== 00 ft_iterative_factorial ====");
	printf("Tesing ex00\n");
    assert(ft_iterative_factorial(0)==1);
	assert(ft_iterative_factorial(1)==1);
	assert(ft_iterative_factorial(2)==2);
	assert(ft_iterative_factorial(3)==6);
	assert(ft_iterative_factorial(4)==24);
	assert(ft_iterative_factorial(5)==120);
	assert(ft_iterative_factorial(-1)==0);
	assert(ft_iterative_factorial(13)==0);
    printf("All tests passed for ex00\n");


	printf("%s\n", "==== 01 ft_recursive_factorial ====");
	printf("Tesing ex01\n");
    assert(ft_recursive_factorial(0)==1);
	assert(ft_recursive_factorial(1)==1);
	assert(ft_recursive_factorial(2)==2);
	assert(ft_recursive_factorial(3)==6);
	assert(ft_recursive_factorial(4)==24);
	assert(ft_recursive_factorial(5)==120);
	assert(ft_recursive_factorial(-1)==0);
	assert(ft_recursive_factorial(13)==0);
    printf("All tests passed for ex01\n");


	printf("%s\n", "==== 02 ft_iterative_power ====");


	printf("%s\n", "==== 03 ft_recursive_power ====");


	printf("%s\n", "==== 04 ft_fibonacci ====");


	printf("%s\n", "==== 05 ft_sqrt ====");


	printf("%s\n", "==== 06 ft_is_prime ====");


	printf("%s\n", "==== 07 ft_find_next_prime ====");


	printf("%s\n", "==== 08 ft_eight_queens_puzzle ====");


	printf("%s\n", "==== 09 ft_eight_queens_puzzle_2 ====");
	return (0);
}
