#include <stdio.h>
#include <assert.h>

#include "./ex00/ft_generic.c"
#include "./ex01/ft_takes_place.c"
// #include "./ex04/ft_rot42.c"
// #include "./ex05/ft_antidote.c"
// #include "./ex06/ft_destroy.c"
// #include "./ex07/ft_collatz_conjecture.c"
// #include "./ex08/ft_spy.c"
// #include "./ex10/ft_scrambler.c"
// #include "./ex12/ft_door.c"
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

	printf("======== EX 02 ========\n");
	{
	}

	return 0;
}
