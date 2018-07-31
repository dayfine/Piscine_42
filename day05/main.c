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
// #include "./ex16/ft_strcat.c"
// #include "./ex17/ft_strncat.c"
// #include "./ex18/ft_strlcat.c"
// #include "./ex19/ft_strlcpy.c"
// #include "./ex20/ft_putnbr_base.c"
// #include "./ex21/ft_atoi_base.c"
// #include "./ex22/ft_putstr_non_printable.c"
// #include "./ex23/ft_print_memory.c"

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

	printf("==== 01 ft_putnbr ====\n");
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
		assert(ft_atoi("     \t  \n  -6272")==-6272);

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
		char ex04_dest1_std1[10];
		char ex04_dest1_std2[10];

		char ex04_str2[] = "He11o W0rld!";
		char ex04_dest2[20];
		char ex04_dest2_std1[20];
		char ex04_dest2_std2[20];

		printf("Should copy\n");
		{
			ft_strncpy(ex04_dest1, ex04_str1, 1);
			strncpy(ex04_dest1_std1, ex04_str1, 1);

			ft_strncpy(ex04_dest2, ex04_str2, 13);
			strncpy(ex04_dest2_std1, ex04_str2, 13);

			assert(strcmp(ex04_dest1, "")==0);
			assert(strcmp(ex04_dest2, "He11o W0rld!")==0);

			assert(strcmp(ex04_dest1, ex04_dest1_std1)==0);
			assert(strcmp(ex04_dest2, ex04_dest2_std1)==0);
		}

		printf("Should fill if str is shorter than n\n");
		{
			ft_strncpy(ex04_dest1, ex04_str1, 2);
			strncpy(ex04_dest1_std2, ex04_str1, 2);

			ft_strncpy(ex04_dest2, ex04_str2, 15);
			strncpy(ex04_dest2_std2, ex04_str2, 15);

			assert(strcmp(ex04_dest1, "")==0);
			assert(strcmp(ex04_dest2, "He11o W0rld!")==0);

			assert(strcmp(ex04_dest1, ex04_dest1_std2)==0);
			assert(strcmp(ex04_dest2, ex04_dest2_std2)==0);
		}


		printf("All tests passed for ex04\n");
	}

	printf("==== 05 ft_strstr ====\n");
	{
		printf("Tesing ex05\n");
		char ex05_haystack[] = "hey stack!";
		char ex05_needle1[] = "";
		char ex05_needle2[] = "stack1";
		char ex05_needle3[] = "stack!";

		printf("Should return haystack if needle is empty\n");
		{
			assert(strstr(ex05_haystack, ex05_needle1)==ex05_haystack);
			assert(ft_strstr(ex05_haystack, ex05_needle1)==ex05_haystack);
		}

		printf("Should return NULL if not found\n");
		{
			assert(strstr(ex05_haystack, ex05_needle2)==NULL);
			assert(ft_strstr(ex05_haystack, ex05_needle2)==NULL);
		}

		printf("Should return index of first letter matched\n");
		{
			assert(strstr(ex05_haystack, ex05_needle3)==&ex05_haystack[4]);
			assert(ft_strstr(ex05_haystack, ex05_needle3)==&ex05_haystack[4]);
		}

		printf("All tests passed for ex05\n");
	}

	printf("==== 06 ft_strcmp ====\n");
	{
		printf("Tesing ex06\n");
		char ex06_str1[] = "hey stack!";
		char ex06_str2[] = "hey stack0";
		char ex06_str3[] = "hay stack!";
		char ex06_str4[] = "hEy stacl!";
		char ex06_str5[] = "hdz tubbj!";
		char ex06_str6[] = "hdy stack!";
		char ex06_str7[] = "hey stack!";

		printf("Should compare and return differences\n");
		{
			assert(strcmp(ex06_str1, ex06_str2)==-15);
			assert(strcmp(ex06_str1, ex06_str3)==4);
			assert(strcmp(ex06_str1, ex06_str4)==32);
			assert(strcmp(ex06_str1, ex06_str5)==1);
			assert(strcmp(ex06_str1, ex06_str6)==1);
			assert(strcmp(ex06_str1, ex06_str7)==0);

			assert(ft_strcmp(ex06_str1, ex06_str2)==-15);
			assert(ft_strcmp(ex06_str1, ex06_str3)==4);
			assert(ft_strcmp(ex06_str1, ex06_str4)==32);
			assert(ft_strcmp(ex06_str1, ex06_str5)==1);
			assert(ft_strcmp(ex06_str1, ex06_str6)==1);
			assert(ft_strcmp(ex06_str1, ex06_str7)==0);
		}

		printf("All tests passed for ex06\n");
	}

	printf("==== 07 ft_strncmp ====\n");
	{
		printf("Tesing ex07\n");
		char ex07_str1[] = "hey stack!";
		char ex07_str2[] = "hey st4ck0";
		char ex07_str3[] = "hey stack!123456789";

		printf("Should compare and return differences\n");
		{
			assert(strncmp(ex07_str1, ex07_str2, 3)==0);
			assert(strncmp(ex07_str1, ex07_str2, 5)==0);
			assert(strncmp(ex07_str1, ex07_str2, 7)==45);
			assert(strncmp(ex07_str1, ex07_str2, 9)==45);
			assert(strncmp(ex07_str1, ex07_str2, 11)==45);
			assert(strncmp(ex07_str1, ex07_str2, 13)==45);

			assert(ft_strncmp(ex07_str1, ex07_str2, 3)==0);
			assert(ft_strncmp(ex07_str1, ex07_str2, 5)==0);
			assert(ft_strncmp(ex07_str1, ex07_str2, 7)==45);
			assert(ft_strncmp(ex07_str1, ex07_str2, 9)==45);
			assert(ft_strncmp(ex07_str1, ex07_str2, 11)==45);
			assert(ft_strncmp(ex07_str1, ex07_str2, 13)==45);
		}

		printf("Should ignore characters AFTER '\\n'\n");
		{
			assert(strncmp(ex07_str1, ex07_str3, 10)==0);
			assert(strncmp(ex07_str1, ex07_str3, 13)==-49);
			assert(strncmp(ex07_str1, ex07_str3, 99)==-49);

			assert(ft_strncmp(ex07_str1, ex07_str3, 10)==0);
			assert(ft_strncmp(ex07_str1, ex07_str3, 13)==-49);
			assert(ft_strncmp(ex07_str1, ex07_str3, 99)==-49);
		}

		printf("All tests passed for ex07\n");
	}

	printf("==== 08 ft_strupcase ====\n");
	{
		printf("Tesing ex08\n");
		char ex08_str1[] = "\t ab?%%$#==1343449-)(8";
		char ex08_str2[] = "HELLO WORLD";

		printf("Should convert lower case letters to upper case\n");
		{
			assert(strcmp(ft_strupcase(ex08_str1), "\t AB?%%$#==1343449-)(8")==0);
			assert(strcmp(ft_strupcase(ex08_str2), "HELLO WORLD")==0);
		}

		printf("All tests passed for ex08\n");
	}

	printf("==== 09 ft_strlowcase ====\n");
	{
		printf("Tesing ex09\n");
		char ex09_str1[] = "\t AB?%%$#==1343449-)(8";
		char ex09_str2[] = "hello world";

		printf("Should convert upper case letters to lower case\n");
		{
			assert(strcmp(ft_strlowcase(ex09_str1), "\t ab?%%$#==1343449-)(8")==0);
			assert(strcmp(ft_strlowcase(ex09_str2), "hello world")==0);
		}

		printf("All tests passed for ex09\n");
	}

	printf("==== 10 ft_strcapitalize ====\n");
	{
		printf("Tesing ex10\n");
		char ex10_str1[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
		char ex10_str2[] = "he110?w0r1D+xOxO";

		printf("Should capitalize each word in string\n");
		{
			assert(strcmp(ft_strcapitalize(ex10_str1), "Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un")==0);
			assert(strcmp(ft_strcapitalize(ex10_str2), "He110?W0r1d+Xoxo")==0);
		}

		printf("All tests passed for ex10\n");
	}

	printf("==== 11 ft_str_is_alpha ====\n");
	{
		printf("Tesing ex11\n");

		printf("Should return 1 for empty string\n");
		{
			assert(ft_str_is_alpha("")==1);
		}

		printf("Should return true for all alphabetical characters\n");
		{
			assert(ft_str_is_alpha("aahtuiheUUUrRE")==1);
		}

		printf("Should return false when there is other character\n");
		{
			assert(ft_str_is_alpha("aahtui heUUUrRE")==0);
			assert(ft_str_is_alpha("12ER")==0);
		}

		printf("All tests passed for ex11\n");
	}

	printf("==== 12 ft_str_is_numeric ====\n");
	{
		printf("Tesing ex12\n");

		printf("Should return 1 for empty string\n");
		{
			assert(ft_str_is_numeric("")==1);
		}

		printf("Should return true for all numeric characters\n");
		{
			assert(ft_str_is_numeric("134342")==1);
		}

		printf("Should return false when there is other character\n");
		{
			assert(ft_str_is_numeric("13141.34")==0);
			assert(ft_str_is_numeric("erete 1231")==0);
		}

		printf("All tests passed for ex12\n");
	}

	printf("==== 13 ft_str_is_lowercase ====\n");
	{
		printf("Tesing ex13\n");

		printf("Should return 1 for empty string\n");
		{
			assert(ft_str_is_lowercase("")==1);
		}

		printf("Should return true for all lower case characters\n");
		{
			assert(ft_str_is_lowercase("abcd")==1);
		}

		printf("Should return false when there is other character\n");
		{
			assert(ft_str_is_lowercase("aihi Ai")==0);
			assert(ft_str_is_lowercase("erete 1231")==0);
		}

		printf("All tests passed for ex13\n");
	}

	printf("==== 14 ft_str_is_uppercase ====\n");
	{
		printf("Tesing ex14\n");

		printf("Should return 1 for empty string\n");
		{
			assert(ft_str_is_uppercase("")==1);
		}

		printf("Should return true for all upper case characters\n");
		{
			assert(ft_str_is_uppercase("XXTTE")==1);
		}

		printf("Should return false when there is other character\n");
		{
			assert(ft_str_is_uppercase("ETW Ai")==0);
			assert(ft_str_is_uppercase("erERERete 1231")==0);
		}

		printf("All tests passed for ex14\n");
	}

	printf("==== 15 ft_str_is_printable ====\n");
	{
		printf("Tesing ex15\n");

		printf("Should return 1 for empty string\n");
		{
			assert(ft_str_is_printable("")==1);
		}

		printf("Should return true for all upper case characters\n");
		{
			assert(ft_str_is_printable("XXTTE++++++++")==1);
		}

		printf("Should return false when there is other character\n");
		{
			assert(ft_str_is_printable("ETW Ai÷\t")==0);
			assert(ft_str_is_printable("erERERete 1231\n")==0);
		}

		printf("All tests passed for ex15\n");
	}
}
