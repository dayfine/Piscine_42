#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "./ft_putchar.c"
#include "./ex00/ft_putstr.c"
#include "./ex01/ft_putnbr.c"
#include "./ex02/ft_atoi.c"
#include "./ex03/ft_strcpy.c"
#include "./ex04/ft_strncpy.c"
#include "./ex05/ft_strstr.c"
#include "./ex06/ft_strcmp.c"
#include "./ex07/ft_strncmp.c"
#include "./ex08/ft_strupcase.c"
#include "./ex09/ft_strlowcase.c"
#include "./ex10/ft_strcapitalize.c"
#include "./ex11/ft_str_is_alpha.c"
#include "./ex12/ft_str_is_numeric.c"
#include "./ex13/ft_str_is_lowercase.c"
#include "./ex14/ft_str_is_uppercase.c"
#include "./ex15/ft_str_is_printable.c"
#include "./ex16/ft_strcat.c"
#include "./ex17/ft_strncat.c"
#include "./ex18/ft_strlcat.c"
#include "./ex19/ft_strlcpy.c"
#include "./ex20/ft_putnbr_base.c"
#include "./ex21/ft_atoi_base.c"
#include "./ex22/ft_putstr_non_printable.c"
#include "./ex23/ft_print_memory.c"

int   main(void)
{
	printf("==== 00 ft_putstr ====\n");
	{
		printf("You should see on next line: ''\n");
		ft_putstr("");
		printf("\n");
		printf("You should see on next line: 'The meaning of life is 42.'\n");
		ft_putstr("The meaning of life is 42.");
		printf("\n");
	}

	printf("==== 00 ft_putnbr ====\n");
	{
		printf("Putting: '-100'\n");
		ft_putnbr(-100);
		printf("\n");
		printf("Putting: '0'\n");
		ft_putnbr(0);
		printf("\n");
		printf("Putting: '123'\n");
		ft_putnbr(123);
		printf("\n");
	}

	printf("==== 02 ft_atoi ====\n");
	{
		printf("Tesing ex02\n");

		assert(ft_atoi(" 98993489")==98993489);
		assert(ft_atoi("tutorialspoint.com")==0);
		assert(ft_atoi("a")==0);
		assert(ft_atoi("abc")==0);
		assert(ft_atoi(" -42")==-42);
		assert(ft_atoi(" 14343 and abc")==14343);
		assert(ft_atoi("-91283472332")==-2147483648);
		assert(ft_atoi("91283472332")==2147483647);
		assert(ft_atoi("11111191283472332")==2147483647);

		printf("All tests passed for ex02\n");
	}

	printf("==== 03 ft_strcpy ====\n");
	{
		printf("Tesing ex03\n");
		char ex03_str1[] = "";
		char ex03_dest1[10];
		char ex03_dest1_std[10];

		char ex03_str2[] = "He11o W0rld!";
		char ex03_dest2[13];
		char ex03_dest2_std[13];

		printf("Should copy and return same result as the built in version\n");
		{
			ft_strcpy(ex03_dest1, ex03_str1);
			ft_strcpy(ex03_dest2, ex03_str2);
			strcpy(ex03_dest1_std, ex03_str1);
			strcpy(ex03_dest2_std, ex03_str2);

			assert(strcmp(ex03_dest1, "")==0);
			assert(strcmp(ex03_dest2, "He11o W0rld!")==0);
			assert(strcmp(ex03_dest1, ex03_dest1_std)==0);
			assert(strcmp(ex03_dest2, ex03_dest2_std)==0);
		}

		printf("All tests passed for ex03\n");
	}

	printf("==== 04 ft_strncpy ====\n");
	{
		printf("Tesing ex04\n");
		char ex04_str1[] = "";
		char ex04_dest1[10];
		char ex04_dest1_std[10];

		char ex04_str2[] = "He11o W0rld!";
		char ex04_dest2[13];
		char ex04_dest2_std[13];

		printf("Should copy\n");
		{
			ft_strncpy(ex04_dest1, ex04_str1, 0);
			strncpy(ex04_dest1_std, ex04_str1, 0);

			ft_strncpy(ex04_dest2, ex04_str2, 9);
			strncpy(ex04_dest2_std, ex04_str2, 9);

			assert(strcmp(ex04_dest1, "")==0);
			assert(strcmp(ex04_dest2, "He11o W0r")==0);

			printf("c: '%s'\n", ex04_dest1);
			printf("c: '%s'\n", ex04_dest1_std);
			printf("c: '%s'\n", ex04_dest2);
			printf("c: '%s'\n", ex04_dest2_std);

			assert(strcmp(ex04_dest1, ex04_dest1_std)==0);
			assert(strcmp(ex04_dest2, ex04_dest2_std)==0);
		}

		printf("Should fill if str is shorter than n\n");
		{
			ft_strncpy(ex04_dest1, ex04_str1, 2);
			ft_strncpy(ex04_dest2, ex04_str2, 13);
			strncpy(ex04_dest1_std, ex04_str1, 2);
			strncpy(ex04_dest2_std, ex04_str2, 13);

			assert(strcmp(ex04_dest1, "")==0);
			assert(strcmp(ex04_dest2, "He11o W0rld!")==0);
			assert(strcmp(ex04_dest1, ex04_dest1_std)==0);
			assert(strcmp(ex04_dest2, ex04_dest2_std)==0);
		}


		printf("All tests passed for ex04\n");
	}
}
