#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <limits.h>

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
		printf("Putting: '2147483647'\n");
		ft_putnbr(INT_MAX);
		printf("\n");
		printf("Putting: '-2147483648'\n");
		ft_putnbr(INT_MIN);
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
		assert(ft_atoi("\t\n\v\f\r +256")==256);

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

			ft_strncpy(ex04_dest2, ex04_str2, 20);
			strncpy(ex04_dest2_std2, ex04_str2, 20);

			assert(strcmp(ex04_dest1, "")==0);
			assert(strcmp(ex04_dest2, "He11o W0rld!")==0);

			assert(strcmp(ex04_dest1, ex04_dest1_std2)==0);
			assert(strcmp(ex04_dest2, ex04_dest2_std2)==0);
		}

		printf("What if n < len(str)?\n");
		{
			ft_strncpy(ex04_dest2, "YY", 1);
			strncpy(ex04_dest2_std2, "YY", 1);

			assert(strcmp(ex04_dest2, "Ye11o W0rld!")==0);
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
		char ex06_str8[] = "";
		char ex06_str9[] = "hey";
		char ex06_str10[] = "hey s";
		char ex06_str11[] = "hfz";

		printf("Should compare and return differences\n");
		{
			assert(strcmp(ex06_str1, ex06_str2)==-15);
			assert(strcmp(ex06_str1, ex06_str3)==4);
			assert(strcmp(ex06_str1, ex06_str4)==32);
			assert(strcmp(ex06_str1, ex06_str5)==1);
			assert(strcmp(ex06_str1, ex06_str6)==1);
			assert(strcmp(ex06_str1, ex06_str7)==0);
			assert(strcmp(ex06_str1, ex06_str8)==104);
			assert(strcmp(ex06_str1, ex06_str9)==32);
			assert(strcmp(ex06_str1, ex06_str10)==116);
			assert(strcmp(ex06_str1, ex06_str11)==-1);

			assert(ft_strcmp(ex06_str1, ex06_str2)==-15);
			assert(ft_strcmp(ex06_str1, ex06_str3)==4);
			assert(ft_strcmp(ex06_str1, ex06_str4)==32);
			assert(ft_strcmp(ex06_str1, ex06_str5)==1);
			assert(ft_strcmp(ex06_str1, ex06_str6)==1);
			assert(ft_strcmp(ex06_str1, ex06_str7)==0);
			assert(ft_strcmp(ex06_str1, ex06_str8)==104);
			assert(ft_strcmp(ex06_str1, ex06_str9)==32);
			assert(ft_strcmp(ex06_str1, ex06_str10)==116);
			assert(ft_strcmp(ex06_str1, ex06_str11)==-1);
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

	printf("==== 16 ft_strcat ====\n");
	{
		printf("Tesing ex16\n");
		char ex16_src[50], ex16_dest[50], ex16_std_dest[50];

		ft_strcpy(ex16_src,  "World!");
		ft_strcpy(ex16_dest, "Hello ");
		ft_strcpy(ex16_std_dest, "Hello ");

		ft_strcat(ex16_dest, ex16_src);
		strcat(ex16_std_dest, ex16_src);

		assert(strcmp(ex16_dest, "Hello World!")==0);
		assert(strcmp(ex16_dest, ex16_std_dest)==0);

		printf("All tests passed for ex16\n");
	}

	printf("==== 17 ft_strncat ====\n");
	{
		printf("Tesing ex17\n");
		char ex17_src[50];
		char ex17_dest1[50], ex17_dest2[50], ex17_dest3[50];
		char ex17_std_dest1[50], ex17_std_dest2[50], ex17_std_dest3[50];

		ft_strcpy(ex17_src,  "World!");
		ft_strcpy(ex17_dest1, "Hello ");
		ft_strcpy(ex17_dest2, "Hello ");
		ft_strcpy(ex17_dest3, "Hello ");
		ft_strcpy(ex17_std_dest1, "Hello ");
		ft_strcpy(ex17_std_dest2, "Hello ");
		ft_strcpy(ex17_std_dest3, "Hello ");

		ft_strncat(ex17_dest1, ex17_src, 0);
		ft_strncat(ex17_dest2, ex17_src, 6);
		ft_strncat(ex17_dest3, ex17_src, 30);
		strncat(ex17_std_dest1, ex17_src, 0);
		strncat(ex17_std_dest2, ex17_src, 6);
		strncat(ex17_std_dest3, ex17_src, 30);

		assert(strcmp(ex17_dest1, "Hello ")==0);
		assert(strcmp(ex17_dest2, "Hello World!")==0);
		assert(strcmp(ex17_dest3, "Hello World!")==0);

		assert(strcmp(ex17_dest1, ex17_std_dest1)==0);
		assert(strcmp(ex17_dest2, ex17_std_dest2)==0);
		assert(strcmp(ex17_dest3, ex17_std_dest3)==0);

		printf("All tests passed for ex17\n");
	}

	printf("==== 18 ft_strlcat ====\n");
	{
		printf("Tesing ex18\n");

		printf("Normal Behavior");
		{
			char ex18_src[50];
			char ex18_dest1[10], ex18_dest2[13], ex18_dest3[50];
			char ex18_std_dest1[10], ex18_std_dest2[13], ex18_std_dest3[50];

			ft_strcpy(ex18_src,  "World!");
			ft_strcpy(ex18_dest1, "Hello ");
			ft_strcpy(ex18_dest2, "Hello ");
			ft_strcpy(ex18_dest3, "Hello ");
			ft_strcpy(ex18_std_dest1, "Hello ");
			ft_strcpy(ex18_std_dest2, "Hello ");
			ft_strcpy(ex18_std_dest3, "Hello ");

			assert(ft_strlcat(ex18_dest1, ex18_src, 10)==12);
			assert(ft_strlcat(ex18_dest2, ex18_src, 13)==12);
			assert(ft_strlcat(ex18_dest3, ex18_src, 50)==12);
			assert(strlcat(ex18_std_dest1, ex18_src, 10)==12);
			assert(strlcat(ex18_std_dest2, ex18_src, 13)==12);
			assert(strlcat(ex18_std_dest3, ex18_src, 50)==12);

			assert(strcmp(ex18_dest1, "Hello Wor")==0);
			assert(strcmp(ex18_dest2, "Hello World!")==0);
			assert(strcmp(ex18_dest3, "Hello World!")==0);
			assert(strcmp(ex18_dest1, ex18_std_dest1)==0);
			assert(strcmp(ex18_dest2, ex18_std_dest2)==0);
			assert(strcmp(ex18_dest3, ex18_std_dest3)==0);
		}

		printf("It will then NUL-terminate, unless dstsize is 0 or the original dst string was longer than dstsize");
		{
			char test[256] = "\0zxcvzxcvzxcvxzcvzxcv";
			assert(ft_strlcat(test, "asdf", 16)==4);
			assert(strcmp(test, "asdf")==0);
			assert(ft_strlcat(test, "asdf", 6)==8);
			assert(strcmp(test, "asdfa")==0);
			assert(ft_strlcat(test, "asdf", 4)==8);
			assert(strcmp(test, "asdfa")==0);
			assert(ft_strlcat(test, "", 16)==5);
			assert(strcmp(test, "asdfa")==0);
			assert(ft_strlcat(test, "asdf", 0)==4);
			assert(strcmp(test, "asdfa")==0);
		}

		printf("All tests passed for ex18\n");
	}

	printf("==== 19 ft_strlcpy ====\n");
	{
		printf("Tesing ex19\n");

		printf("Normal Behavior");
		{
			char ex19_src[50];
			char ex19_dest1[10], ex19_dest2[13], ex19_dest3[50];
			char ex19_std_dest1[10], ex19_std_dest2[13], ex19_std_dest3[50];

			ft_strcpy(ex19_src,  "Hello World!");

			assert(ft_strlcpy(ex19_dest1, ex19_src, 10)==12);
			assert(ft_strlcpy(ex19_dest2, ex19_src, 13)==12);
			assert(ft_strlcpy(ex19_dest3, ex19_src, 50)==12);
			assert(strlcpy(ex19_std_dest1, ex19_src, 10)==12);
			assert(strlcpy(ex19_std_dest2, ex19_src, 13)==12);
			assert(strlcpy(ex19_std_dest3, ex19_src, 50)==12);

			assert(strcmp(ex19_dest1, "Hello Wor")==0);
			assert(strcmp(ex19_dest2, "Hello World!")==0);
			assert(strcmp(ex19_dest3, "Hello World!")==0);
			assert(strcmp(ex19_dest1, ex19_std_dest1)==0);
			assert(strcmp(ex19_dest2, ex19_std_dest2)==0);
			assert(strcmp(ex19_dest3, ex19_std_dest3)==0);
		}

		printf("It will then NUL-terminate, unless dstsize is 0 or the original dst string was longer than dstsize");
		{
			char test19[256] = "\0zxcvzxcvzxcvxzcvzxcv";
			assert(ft_strlcpy(test19, "asdf", 16)==4);
			assert(strcmp(test19, "asdf")==0);
			assert(ft_strlcpy(test19, "uiop", 0)==4);
			assert(strcmp(test19, "asdf")==0);
			assert(ft_strlcpy(test19, "qwerty", 4)==6);
			assert(strcmp(test19, "qwe")==0);
			assert(ft_strlcpy(test19, "", 4)==0);
			assert(strcmp(test19, "")==0);
		}

		printf("All tests passed for ex19\n");
	}

	printf("==== 20 ft_putnbr_base ====\n");
	{
		printf("Tesing ex20\n");
		{
			printf("Should display nothing in case of invalid arguments\n");
			{
				ft_putnbr_base(15, "");
				ft_putnbr_base(15, "1");
				ft_putnbr_base(15, "144");
				ft_putnbr_base(15, "14+35");
				ft_putnbr_base(15, "145-09");
			}

			printf("Should print number in correct radix\n");
			{
				printf("\nBase: '01'\n");
				ft_putnbr_base(15, "01");
				printf("\nBase: '0123456789'\n");
				ft_putnbr_base(15, "0123456789");
				printf("\nBase: '0123456789ABCDEF'\n");
				ft_putnbr_base(15, "0123456789ABCDEF");
				printf("\nBase: 'fivte3n'\n");
				ft_putnbr_base(15, "fivte3n");
				printf("\nBase: '9876543210'\n");
				ft_putnbr_base(15, "9876543210");
				printf("\n");
			}

			printf("Should handle negative numbers\n");
			{
				printf("\nBase: '01'\n");
				ft_putnbr_base(-15, "01");
				printf("\nBase: '0123456789'\n");
				ft_putnbr_base(-15, "0123456789");
				printf("\nBase: '0123456789ABCDEF'\n");
				ft_putnbr_base(-15, "0123456789ABCDEF");
				printf("\nBase: 'fivte3n'\n");
				ft_putnbr_base(-15, "fivte3n");
				printf("\nBase: '9876543210'\n");
				ft_putnbr_base(-15, "9876543210");
				printf("\n");
			}

			printf("Should handle INT_MIN\n");
			{
				printf("\nBase: '0123456789abcdef' Expected: '-80000000'\n");
				ft_putnbr_base(-2147483648, "0123456789abcdef");
				printf("\n");
			}
		}

		printf("All tests passed for ex20\n");
	}

	printf("==== 21 ft_atoi_base ====\n");
	{
		printf("Tesing ex21\n");
		{
			printf("Should return 0 in case of invalid arguments\n");
			{
				assert(ft_atoi_base("15", "")==0);
				assert(ft_atoi_base("15", "1")==0);
				assert(ft_atoi_base("15", "144")==0);
				assert(ft_atoi_base("15", "14+35")==0);
				assert(ft_atoi_base("15", "145-09")==0);
				assert(ft_atoi_base("", "14509")==0);
				assert(ft_atoi_base("x15", "14509")==0);
				assert(ft_atoi_base("+157", "14509")==0);
			}

			printf("Should print number in correct radix\n");
			{
				assert(ft_atoi_base("+1111", "01")==15);
				assert(ft_atoi_base("+15", "0123456789")==15);
				assert(ft_atoi_base("+F", "0123456789ABCDEF")==15);
				assert(ft_atoi_base("+vi", "fivte3n")==15);
				assert(ft_atoi_base("+84", "9876543210")==15);
			}

			printf("Should handle negative numbers\n");
			{
				assert(ft_atoi_base("-1111", "01")==-15);
				assert(ft_atoi_base("-15", "0123456789")==-15);
				assert(ft_atoi_base("-F", "0123456789ABCDEF")==-15);
				assert(ft_atoi_base("-vi", "fivte3n")==-15);
				assert(ft_atoi_base("-84", "9876543210")==-15);
			}
		}

		printf("All tests passed for ex21\n");
	}

	printf("==== 22 ft_putstr_non_printable ====\n");
	{
		printf("Tesing ex22\n");
		{
			printf("Should print normal string\n");
			{
				printf("You should see on next line: ''\n");
				ft_putstr_non_printable("");
				printf("\n");
				printf("You should see on next line: 'The meaning of life is 42.'\n");
				ft_putstr_non_printable("The meaning of life is 42.");
				printf("\n");
			}
			printf("Should convert nonprintable to hex\n");
			{
				printf("You should see on next line: '\\0a'\n");
				ft_putstr_non_printable("\n");
				printf("\n");
				printf("You should see on next line: 'Coucou\\0atu vas bien ?'\n");
				ft_putstr_non_printable("Coucou\ntu vas bien ?");
				printf("\n");
				printf("You should see on next line: 'asdf\\7f\\1fhi\\01\\fflol'\n");
				ft_putstr_non_printable("asdf\x7f\x1fhi\x01\xfflol");
				printf("\n");
			}
		}

		printf("All tests passed for ex22\n");
	}
}
