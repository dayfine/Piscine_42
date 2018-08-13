#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void br(void)
{
	printf("\n");
}

int		randint(int min, int max)
{
	return rand() % (max + 1 - min) + min;
}


char	**make_map(char *sym, int m, int n, int count)
{
	char **matrix = (char **)malloc((m + 1) * sizeof(char*));
	for (int i = 0; i < m; i++)
		matrix[i] = (char *)malloc((n + 1) * sizeof(char));
	matrix[m] = NULL;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			matrix[i][j] = randint(0,  m * n) < count ? sym[1] : sym[0];
		matrix[i][n] = '\0';
	}
	return matrix;
}

void 	print_line(char *str)
{
	while (*str)
		printf("%c ", *str++);
	printf("\n");
}

void 	print_matrix(char **matrix)
{
	while (*matrix)
		print_line(*matrix++);
}
