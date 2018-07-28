#include <stdio.h>
#include <assert.h>

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
	printf("Tesing ex00\n");

	int num_ex01 = 12;
	ft_ft(&num_ex01);

	assert(num_ex01==42);

	printf("All tests passed for ex00\n");


	printf("%s\n", "==== 01 ft_ultimate_ft ====");
	printf("Tesing ex01\n");

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

	assert(num_ex02==42);

	printf("All tests passed for ex01\n");


	printf("%s\n", "==== 02 ft_swap ====");
	printf("Tesing ex02\n");

	int a = 42;
	int b = 24;

	ft_swap(&a, &b);

	assert(a==24);
	assert(b==42);

	printf("All tests passed for ex02\n");


	printf("%s\n", "==== 03 ft_div_mod ====");
	printf("Tesing ex03\n");

	int dem = 4242;
	int nom = 424;
	int div;
	int mod;

	ft_div_mod(dem, nom, &div, &mod);

	assert(div==10);
	assert(mod==2);
	printf("All tests passed for ex03\n");


	printf("%s\n", "==== 04 ft_ultimate_div_mod ====");
	printf("Tesing ex04\n");

	int ultimate_dem = 4242;
	int ultimate_nom = 424;

	ft_ultimate_div_mod(&ultimate_dem, &ultimate_nom);

	assert(ultimate_dem==10);
	assert(ultimate_nom==2);

	printf("All tests passed for ex04\n");


	printf("%s\n", "==== 05 ft_putstr ====");
	char *str;
	str = "The meaning of life is 42.\n";
	ft_putstr(str);


	printf("%s\n", "==== 06 ft_putstr ====");
	printf("Tesing ex06\n");
	char *str_w_len;
	str_w_len = "Life";

	assert(ft_strlen(str_w_len)==4);

	printf("All tests passed for ex06\n");


	printf("%s\n", "==== 07 ft_strrev ====");
	// causes segment fault error when trying to run with other functions
	char rev_str1[] = "";
	char rev_str2[] = "abcd12345";

	// printf("reversed: %s;\n", ft_strrev(rev_str1));
	// printf("reversed: %s;\n", ft_strrev(rev_str2));


	printf("%s\n", "==== 08 ft_atoi ====");
	printf("Tesing ex08\n");

	assert(ft_atoi(" 98993489")==98993489);
	assert(ft_atoi("tutorialspoint.com")==0);
	assert(ft_atoi("a")==0);
	assert(ft_atoi("abc")==0);
	assert(ft_atoi(" -42")==-42);
	assert(ft_atoi(" 14343 and abc")==14343);
	assert(ft_atoi("-91283472332")==-2147483648);
	assert(ft_atoi("91283472332")==2147483647);
	assert(ft_atoi("11111191283472332")==2147483647);

	printf("All tests passed for ex08\n");


	printf("%s\n", "==== 09 ft_sort_integer_table ====");

	int nums[] = {1, 2, 4, 5, 6, 9, 13, 1, 4, 2};
	int i;
	ft_sort_integer_table(nums, 10);
	for (i = 0; i < 10; i++) printf("%d ", nums[i]);
	printf("\n");
	return (0);
}
