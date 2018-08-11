#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "./ex00/ft_utils.c"


void br(void)
{
	printf("\n");
}

int main(void)
{
	printf("%s\n", "==== Utils: ft_remove_spaces ====");
	{
		printf("Tesing `ft_remove_spaces`\n");

		assert(strcmp(ft_remove_spaces(" 98993489"), "98993489")==0);
		assert(strcmp(ft_remove_spaces("1 +98993489"), "1+98993489")==0);
		assert(strcmp(ft_remove_spaces("1 + (5 + 3)*98993 %%489"), "1+(5+3)*98993%%489")==0);
		assert(strcmp(ft_remove_spaces("-1 * (4 + -25 +3) *  98993 %% ((1 + 2489) * 134 )"),\
										 "-1*(4+-25+3)*98993%%((1+2489)*134)")==0);
		printf("All tests passed for `ft_remove_spaces`\n");
	}

	printf("%s\n", "==== Utils: ft_atoi ====");
	{
		printf("Tesing `ft_atoi`\n");

		assert(ft_atoi(" 98993489")==98993489);
		assert(ft_atoi("tutorialspoint.com")==0);
		assert(ft_atoi("a")==0);
		assert(ft_atoi("abc")==0);
		assert(ft_atoi(" -42")==-42);
		assert(ft_atoi(" 14343 and abc")==14343);
		assert(ft_atoi("-91283472332")==-2147483648);
		assert(ft_atoi("91283472332")==2147483647);
		assert(ft_atoi("11111191283472332")==2147483647);

		printf("All tests passed for `ft_atoi`\n");
	}
}
