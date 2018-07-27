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
	printf("%s\n", "==== 00 ft_ft ====");
	int num_ex01 = 12;

	ft_ft(&num_ex01);
	printf("%d\n", num_ex01);


	printf("%s\n", "==== 01 ft_ultimate_ft ====");
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


	printf("%s\n", "==== 02 ft_swap ====");
	int a = 42;
	int b = 24;

	printf("a: %d ; b: %d\n", a, b);
	ft_swap(&a, &b);
	printf("swapped\n");
	printf("a: %d ; b: %d\n", a, b);


	printf("%s\n", "==== 03 ft_div_mod ====");

	int dem = 4242;
	int nom = 424;
	int div;
	int mod;

	ft_div_mod(dem, nom, &div, &mod);
	printf("dividing %d by %d\n", dem, nom);
	printf("div: %d ; mod: %d\n", div, mod);


	printf("%s\n", "==== 04 ft_ultimate_div_mod ====");
	int ultimate_dem = 4242;
	int ultimate_nom = 424;

	printf("dividing %d by %d\n", ultimate_dem, ultimate_nom);
	ft_ultimate_div_mod(&ultimate_dem, &ultimate_nom);
	printf("div: %d ; mod: %d\n", ultimate_dem, ultimate_nom);


	printf("%s\n", "==== 05 ft_putstr ====");
	char *str;
	str = "The meaning of life is 42.\n";
	ft_putstr(str);

	return (0);
}
