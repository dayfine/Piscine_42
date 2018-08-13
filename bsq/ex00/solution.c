/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:11:51 by dfan              #+#    #+#             */
/*   Updated: 2018/08/13 11:11:52 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct s_solution {
	char	**matrix;
	char	*symbols;
	int		width;
	int		height;
	int		max_size;
	int		max_x;
	int		max_y;
}				t_solution;

void update_solution(t_solution *s, int val, int x, int y)
{
	if (val > s->max_size)
	{
		s->max_size = val;
		s->max_x = x;
		s->max_y = y;
	}
}

int		min(int x, int y, int z)
{
	if (x > y)
		return (y > z ? z : y);
	else
		return (x > z ? z : x);
}

void	print_int_row(int *row, int size)
{
	int i = -1;
	while (++i < size)
		printf("%d ", row[i]);
	printf("\n");
}

void	solver(t_solution *s)
{
	int i;
	int j;
	int *dp0;
	int *dp1;

	dp0 = malloc(sizeof(int) * (s->width + 1));
	j = -1;
	while (++j < s->width)
		dp0[j] = s->matrix[0][j] == s->symbols[0];
	i = 0;
	while (++i < s->height)
	{
		dp1 = malloc(sizeof(int) * (s->width + 1));
		dp1[0] = s->matrix[i][0] == s->symbols[0];
		j = 0;
		while (++j < s->width)
		{
			dp1[j] = (s->matrix[i][j] == s->symbols[0]) && \
					(1 + min(dp1[j - 1], dp0[j], dp0[j - 1]));
			update_solution(s, dp1[j], i, j);
		}
		free(dp0);
		dp0 = dp1;
	}
	free(dp1);
}
