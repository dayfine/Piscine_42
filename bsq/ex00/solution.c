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

#include "ft.h"

void		update_solution(t_solution *s, int val, int x, int y)
{
	if (val > s->max_size)
	{
		s->max_size = val;
		s->max_x = x;
		s->max_y = y;
	}
}

t_solution	*create_solution(void)
{
	t_solution *solution;

	solution = malloc(t_solution);
	return (solution);
}

void		print_board(t_solution *s)
{
}

void		apply_solution(t_solution *s)
{
}
