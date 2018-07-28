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
	printf("Tesing ex02\n");
	assert(ft_iterative_power(0, 0)==1);
	assert(ft_iterative_power(1, 0)==1);
	assert(ft_iterative_power(0, 1)==0);
	assert(ft_iterative_power(0, -1)==0);
	assert(ft_iterative_power(100, -2)==0);
	assert(ft_iterative_power(1, -2)==0);
	assert(ft_iterative_power(2, 3)==8);
	assert(ft_iterative_power(2, 10)==1024);
	assert(ft_iterative_power(5, 2)==25);
	assert(ft_iterative_power(7, 3)==343);
	printf("All tests passed for ex02\n");


	printf("%s\n", "==== 03 ft_recursive_power ====");
	printf("Tesing ex03\n");
	assert(ft_recursive_power(0, 0)==1);
	assert(ft_recursive_power(1, 0)==1);
	assert(ft_recursive_power(0, 1)==0);
	assert(ft_recursive_power(0, -1)==0);
	assert(ft_recursive_power(100, -2)==0);
	assert(ft_recursive_power(1, -2)==0);
	assert(ft_recursive_power(2, 3)==8);
	assert(ft_recursive_power(2, 10)==1024);
	assert(ft_recursive_power(5, 2)==25);
	assert(ft_recursive_power(7, 3)==343);
	printf("All tests passed for ex03\n");


	printf("%s\n", "==== 04 ft_fibonacci ====");
	printf("Tesing ex04\n");
	assert(ft_fibonacci(-2)==0);
	assert(ft_fibonacci(-1)==0);
	assert(ft_fibonacci(0)==0);
	assert(ft_fibonacci(1)==1);
	assert(ft_fibonacci(2)==1);
	assert(ft_fibonacci(3)==2);
	assert(ft_fibonacci(4)==3);
	assert(ft_fibonacci(5)==5);
	assert(ft_fibonacci(6)==8);
	printf("All tests passed for ex04\n");


	printf("%s\n", "==== 05 ft_sqrt ====");
	printf("Tesing ex05\n");
	assert(ft_sqrt(-2)==0);
	assert(ft_sqrt(-1)==0);
	assert(ft_sqrt(0)==0);
	assert(ft_sqrt(1)==1);
	assert(ft_sqrt(2)==0);
	assert(ft_sqrt(3)==0);
	assert(ft_sqrt(4)==2);
	assert(ft_sqrt(9)==3);
	assert(ft_sqrt(16)==4);
	printf("All tests passed for ex05\n");


	printf("%s\n", "==== 06 ft_is_prime ====");
	printf("Tesing ex06\n");
	assert(ft_is_prime(-2)==0);
	assert(ft_is_prime(-1)==0);
	assert(ft_is_prime(0)==0);
	assert(ft_is_prime(1)==0);
	assert(ft_is_prime(2)==1);
	assert(ft_is_prime(3)==1);
	assert(ft_is_prime(4)==0);
	assert(ft_is_prime(9)==0);
	assert(ft_is_prime(13)==1);
	assert(ft_is_prime(17)==1);
	assert(ft_is_prime(21)==0);
	printf("All tests passed for ex06\n");


	printf("%s\n", "==== 07 ft_find_next_prime ====");


	printf("%s\n", "==== 08 ft_eight_queens_puzzle ====");


	printf("%s\n", "==== 09 ft_eight_queens_puzzle_2 ====");
	return (0);
}
