#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "./ex00/ft_generic.c"
#include "./ex01/ft_takes_place.c"
#include "./ex04/ft_rot42.c"
#include "./ex05/ft_antidote.c"
#include "./ex06/ft_destroy.c"
#include "./ex07/ft_collatz_conjecture.c"
#include "./ex08/ft_spy.c"
#include "./ex10/ft_scrambler.c"
#include "./ex12/ft_door.c"
// #include "./ex13/ft_compact.c"


void br(void)
{
	printf("\n");
}


int main(void)
{
	printf("======== EX 00 ========\n");
	{
		ft_generic();
	}
	printf("======== EX 01 ========\n");
	{
		ft_takes_place(0);
		br();
		ft_takes_place(7);
		br();
		ft_takes_place(12);
		br();
		ft_takes_place(15);
		br();
		ft_takes_place(23);
		br();
	}

	printf("======== EX 04 ========\n");
	{
		printf("Testing ft_rot42\n");

		char rot16_input[] = "thjJIOJTA)#@)_) (!434254onUBAIBRubaibr";
  		assert(strcmp(ft_rot42(rot16_input),
  			"jxzZYEZJQ)#@)_) (!434254edKRQYRHkrqyrh")==0);

		printf("Tests passed\n");
	}

	printf("======== EX 05 ========\n");
	{
		printf("Testing ft_antidote\n");

  		assert(ft_antidote(1, 2, 3)==2);
		assert(ft_antidote(1, 1, 1)==1);
		assert(ft_antidote(1, 0, 2)==1);
		assert(ft_antidote(1, -1, 0)==0);

		printf("Tests passed\n");
	}

	printf("======== EX 06 ========\n");
	{
		printf("Testing ft_destroy\n");
		int m = 5;
		int n = 5;
		int p = 5;
		int i = 0;
	    int j = 0;
	    char ***list;

	    list = (char ***)malloc((m + 1) * sizeof(char **));
	    assert(list != NULL);
	    for (i = 0; i < m; ++i)
	    {
	        list[i] = (char **)malloc((n + 1) * sizeof(char *));
	        assert(list[i] != NULL);
	        for (j = 0; j < n; ++j)
	        {
	            list[i][j] = (char *)malloc(p * sizeof(char));
	            assert(list[i][j] != NULL);
	            // list[i][j] = strdup("Hello World");
	        }
	        list[i][j] = NULL;
	    }
	    list[i] = NULL;
		ft_destroy(list);

		printf("Tests passed\n");
	}

	printf("======== EX 07 ========\n");
	{
		printf("Testing ft_collatz_conjecture\n");

  		assert(ft_collatz_conjecture(1)==0);
		assert(ft_collatz_conjecture(2)==1);
		assert(ft_collatz_conjecture(9)==19);
		assert(ft_collatz_conjecture(97)==118);
		assert(ft_collatz_conjecture(871)==178);
		assert(ft_collatz_conjecture(6171)==261);

		ft_destroy(list);

		printf("Tests passed\n");
	}

	printf("======== EX 10 ========\n");
	{
		printf("Testing ft_scrambler\n");

		int ONE = 1;
		int TWO = 2;
		int THREE = 3;
		int FOUR = 4;

		int ***a;
		int *b;
		int *******c;
		int ****d;

		int *a1;
		int **a2;

		int *c1;
		int **c2;
		int ***c3;
		int ****c4;
		int *****c5;
		int ******c6;

		int *d1;
		int **d2;
		int ***d3;

		a1 = &ONE;
		a2 = &a1;
		a = &a2;

		b = &TWO;

		c1 = &THREE;
		c2 = &c1;
		c3 = &c2;
		c4 = &c3;
		c5 = &c4;
		c6 = &c5;
		c = &c6;

		d1 = &FOUR;
		d2 = &d1;
		d3 = &d2;
		d = &d3;

		ft_scrambler(a, b, c, d);

		assert(***a == 2);
		assert(*b == 4);
		assert(*******c == 1);
		assert(****d == 3);

		printf("Tests passed\n");
	}

	printf("======== EX 12 ========\n");
	{
		printf("Testing ft_door\n");
		t_door door;

		open_door(&door);
		if (is_door_close(&door))
			open_door(&door);
		if (is_door_open(&door))
			close_door(&door);
		if (door.state == OPEN)
			close_door(&door);
	}

	return 0;
}
