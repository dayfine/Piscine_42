#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "./ex00/ft_rush_core.c"
#include "./ex00/ft_rushes.c"

void br(void)
{
	printf("\n");
}

int main(void)
{
  	printf("%s", rush00(1, 1));
	printf("%s", rush00(3, 1));
	printf("%s", rush00(1, 3));
	printf("%s", rush00(4, 4));
	printf("%s", rush00(6, 8));
	printf("%s", rush00(9, 9));

  	printf("%s", rush01(1, 1));
	printf("%s", rush01(3, 1));
	printf("%s", rush01(1, 3));
	printf("%s", rush01(4, 4));
	printf("%s", rush01(6, 8));
	printf("%s", rush01(9, 9));

  	printf("%s", rush02(1, 1));
	printf("%s", rush02(3, 1));
	printf("%s", rush02(1, 3));
	printf("%s", rush02(4, 4));
	printf("%s", rush02(6, 8));
	printf("%s", rush02(9, 9));

  	printf("%s", rush03(1, 1));
	printf("%s", rush03(3, 1));
	printf("%s", rush03(1, 3));
	printf("%s", rush03(4, 4));
	printf("%s", rush03(6, 8));
	printf("%s", rush03(9, 9));

  	printf("%s", rush04(1, 1));
	printf("%s", rush04(3, 1));
	printf("%s", rush04(1, 3));
	printf("%s", rush04(4, 4));
	printf("%s", rush04(6, 8));
	printf("%s", rush04(9, 9));
}
