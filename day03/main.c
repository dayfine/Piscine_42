#include <stdio.h>

#include "./ft_putchar.c"
#include "./ex00/ft_ft.c"
#include "./ex01/ft_ultimate_ft.c"
#include "./ex02/ft_swap.c"
#include "./ex03/ft_div_mod.c"
#include "./ex04/ft_ultimate_div_mod.c"
#include "./ex05/ft_putstr.c"
#include "./ex06/ft_strlen.c"
#include "./ex07/ft_strrev.c"
#include "./ex08/ft_atoi.c"
#include "./ex09/ft_sort_integer_table.c"


int   main(void)
{
	printf("%s\n", "==== ft_ft ====");
	int num_ex01 = 12;

	ft_ft(&num_ex01);
	printf("%d\n", num_ex01);

	printf("%s\n", "==== ft_ultimate_ft ====");
	int num_ex02 = 2;
	int *ptr1;
	int **ptr2;
	int ***ptr3;
	int ****ptr4;
	int *****ptr5;
	int ******ptr6;
	int *******ptr7;
	int ********ptr8;
	int *********ptr9;

	ptr1 = &num_ex02;
	ptr2 = &ptr1;
	ptr3 = &ptr2;
	ptr4 = &ptr3;
	ptr5 = &ptr4;
	ptr6 = &ptr5;
	ptr7 = &ptr6;
	ptr8 = &ptr7;
	ptr9 = &ptr8;

	ft_ultimate_ft(ptr9);
	printf("%d\n", num_ex02);

	return (0);
}
