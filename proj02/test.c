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

		printf("Basic number tests\n");
		{
			assert(eval(" 0 ")==0);
			assert(eval("-0")==0);
			assert(eval("- (-0)")==0);
			assert(eval("1234 ")==1234);
			assert(eval("- -65535")==65535);
		}

		printf("Basic parenthesis tests\n");
		{
			assert(eval(" ((((0)) )) ")==0);
			assert(eval("-((-(- 0))")==0);
			assert(eval("-( (-(-123))")==-123);
			assert(eval("( ( 1) +((1 )))")==2);
			assert(eval("((15 )  / ((3) )")==5);
		}

		printf("Simple add/sub Tests\n");
		{
			assert(eval("1+98993489")==98993490);
			assert(eval("(1 + 98993489)")==98993490);
			assert(eval("1 - -98993489")==98993490);
			assert(eval("1 - - (2 + 3) - (-4 )+ (5 + (6 +7)+8--9+10)")==55);
			assert(eval("((55 -10-9)-8-7 - 6+ -5 - 4 -3 +(-2 -1))")==0);
		}

		printf("Simple mul/div/mod Tests\n");
		{
			assert(eval("2 * 2")==4);
			assert(eval("3 * (3 * 3)")==27);
			assert(eval("((-5 * -4) * (3*2 *1))")==120);
			assert(eval("10000/   40")==250);
			assert(eval("77  / 75")==1);
			assert(eval("1+3  / 2")==2);
			assert(eval("1+3  / -2")==0);
			assert(eval("1/4+1 /3 +  1  / 2")==0);
			assert(eval("1 + (5 + 3)*98993 %489")==254);
		}

		printf("Random Tests\n");
		{
			assert(eval("(-589 + 947 + -944)")==-586);
			assert(eval("-388 * 829")==-321652);
			assert(eval("(((-161 / -82 / 178) + -171) / (443 - -106 - 229 % (-177 * 49)))")==0);
			assert(eval("(429 / 568 * 793) - 802")==-802);
			assert(eval("-444 - ((664 / 476) + -972) + (-120 * -284) - 401 % 23")==34597);
			assert(eval("(-724 + 110) - (-881 * 354) % 51")==-605);
			assert(eval("(-347 - 179 + 196 + 2) + 664 + -535 % -599")==-199);
			assert(eval("(-413 / (114 - 462)) % (-637 + 564 - -592) % (-278 * -994 / (178 * 522 - 36))")==1);
			assert(eval("-897 + -458")==-1355);
			assert(eval("-41 * -250 + 351 / 114 / -670 + -280")==9970);
			assert(eval("(-779 % (610 * 229 / -279) % (612 / 176 * -720))")==-279);
			assert(eval("((828 / 716 * -824) % (305 % 281 + -172 - -959 + -508))")==-218);
			assert(eval("418 % -865 + 187 / 217 / 156 % -898")==418);
			assert(eval("-289 - -217 - 640 * -658")==421048);
			assert(eval("(359 + 453) * 300 * (-682 + 712 % 355 % 644)")==-165648000);
			assert(eval("(483 / -62) * 785 % (496 * -339) * (153 * (17 / 287)) + 680 + -449'")==231);
			assert(eval("554 / (643 + -697 * -844) - -525")==525);
			assert(eval("(745 - 524 * 288 + -598) + 709")==-150056);
			assert(eval("752 / (-570 * -374) + -173 * (-196 + 579)")==-66259);
			assert(eval("(537 * (-779 - 433 / 524) - (410 * 93) % 25 / -955)")==-418323);
		}

		printf("All tests passed for `eval`\n");
	}
}
