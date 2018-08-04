#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "./ex00/match.c"
#include "./ex01/nmatch.c"


void br(void)
{
	printf("\n");
}

int main(void)
{
	printf("======== EX 00 ========\n");
	{
		printf("should match without star\n");
		{
			assert(match("", "")==1);
			assert(match("a", "a")==1);
			assert(match("1314\t a", "1314\t a")==1);
			assert(match("\t\t", "\t\t")==1);
			assert(match("  arerewrew", "  arerewrew")==1);
			assert(match("700000", "700000")==1);
		}

		printf("should match * with everything\n");
		{
			assert(match("", "*")==1);
			assert(match("", "**")==1);
			assert(match("", "***")==1);
			assert(match("", "****")==1);
			assert(match("", "*****")==1);
			assert(match("ijoi *?$\\x\trijwprpjw ", "*")==1);
			assert(match("ijoi *?$\\x\trijwprpjw ", "**")==1);
			assert(match("ijoi *?$\\x\trijwprpjw ", "***")==1);
			assert(match("ijoi *?$\\x\trijwprpjw ", "****")==1);
			assert(match("ijoi *?$\\x\trijwprpjw ", "*****")==1);
		}
		printf("more matching tests\n");
		{
			assert(match("banana", "bana*")==1);
			assert(match("banana", "b*na*")==1);
			assert(match("banana", "b*")==1);
			assert(match("banana", "*a")==1);
			assert(match("banana", "*a*")==1);
			assert(match("banana", "*ana*")==1);
			assert(match("banana", "*na*")==1);
			assert(match("banana", "*an*")==1);
		}
		printf("non-matching tests\n");
		{
			assert(match("", "x")==0);
			assert(match("a", "ax")==0);
			assert(match("1314\t a", "1314\t ax")==0);
			assert(match("\t\t", "\t\tx")==0);
			assert(match("  arerewrew", "  arerewrewx")==0);
			assert(match("700000", "700000x")==0);
			assert(match("banana", "bana*x")==0);
			assert(match("banana", "b*na*x")==0);
			assert(match("banana", "b*x")==0);
			assert(match("banana", "*ax")==0);
			assert(match("banana", "*a*x")==0);
			assert(match("banana", "*ana*x")==0);
			assert(match("banana", "*na*x")==0);
			assert(match("banana", "*an*x")==0);
		}
		printf("EX00 Completed\n");
	}
	printf("======== EX 01 ========\n");
	{
		printf("count some nmatch\n");
		{
			assert(nmatch("", " ")==0);
			assert(nmatch("x", "x*y")==0);
			assert(nmatch("", "**")==1);
			assert(nmatch("abcbd", "*b*")==2);
			assert(nmatch("abc", "a**")==3);
			assert(nmatch("abcd", "a***")==10);
		}
		printf("EX01 Completed\n");
	}

	return (0);
}
