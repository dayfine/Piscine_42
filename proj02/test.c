#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "./ex00/ft_utils.c"
#include "./ex00/evals.c"

void br(void)
{
	printf("\n");
}

int eval(char *str)
{
	char *expr;
	char **expr_ptr;

	expr = ft_remove_spaces(str);
	expr_ptr = &expr;
	return (handle_low_order_op(expr_ptr));
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

	printf("%s\n", "==== eval: eval ====");
	{
		printf("Tesing `eval`\n");

		assert(eval("1+98993489")==98993490);
		assert(eval("1 + 98993489")==98993490);
		assert(eval("1 - -98993489")==98993490);

		assert(eval("1 + (5 + 3)*98993 %489")==254);
		assert(eval("1 + (5 + 3)*10 %7 ")==4);

		printf("All tests passed for `eval`\n");
	}
}
