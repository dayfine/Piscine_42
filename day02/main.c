#include <stdio.h>

#include "./ft_putchar.c"
#include "./ex00/ft_print_alphabet.c"
#include "./ex01/ft_print_reverse_alphabet.c"
#include "./ex02/ft_print_numbers.c"
#include "./ex03/ft_is_negative.c"
#include "./ex04/ft_print_comb.c"
#include "./ex05/ft_print_comb2.c"
#include "./ex06/ft_putnbr.c"
#include "./ex07/ft_print_combn.c"


int   main(void)
{
	printf("%s\n", "==== Alphbet ====");
	ft_print_alphabet();

	printf("%s\n", "==== Reverse Alphbet ====");
	ft_print_reverse_alphabet();

	printf("%s\n", "==== Numbers ====");
	ft_print_numbers();

	printf("%s\n", "==== Is Negative ====");
	ft_is_negative(5);
	ft_is_negative(0);
	ft_is_negative(-5);

	printf("%s\n", "==== Print Comb ====");
	ft_print_comb();

	printf("%s\n", "==== Print Comb 2 ====");
	ft_print_comb2();

	printf("%s\n", "==== Put Numbers ====");
	ft_putnbr(42);
    ft_putnbr(1234);
	return (0);
}
