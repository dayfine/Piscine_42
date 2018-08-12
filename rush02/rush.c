#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "./ex00/ft_rush_core.c"
#include "./ex00/ft_rushes.c"

static char	*(*rushes[6])(int, int) = {
	rush00, rush01, rush02, rush03, rush04, NULL
};

int		main(int argc, char **argv)
{
	assert(argc == 4);
	printf("%s", rushes[atoi(argv[1])](atoi(argv[2]), atoi(argv[3])));
	return (0);
}
