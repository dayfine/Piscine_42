/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bsq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:11:51 by dfan              #+#    #+#             */
/*   Updated: 2018/08/13 11:11:52 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "ft.h"

int		min(int x, int y, int z)
{
	if (x > y)
		return (y > z ? z : y);
	else
		return (x > z ? z : x);
}

void	find_bsq(t_solution *s)
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
			dp1[j] = (s->matrix[i][j] != s->symbols[0]) ? 0 : \
					(1 + min(dp1[j - 1], dp0[j], dp0[j - 1]));
			update_solution(s, dp1[j], i, j);
		}
		free(dp0);
		dp0 = dp1;
	}
	free(dp1);
}
