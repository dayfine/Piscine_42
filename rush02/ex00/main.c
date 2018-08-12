/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 11:54:03 by dfan              #+#    #+#             */
/*   Updated: 2018/08/12 11:59:40 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_rushes.h"
#include "ft_utils.h"

static char	*(*g_rushes[6])(int, int) = {
	rush00, rush01, rush02, rush03, rush04, NULL
};

void	print_answer(int idx, int answer_count, int w, int h)
{
	if (answer_count)
		ft_putstr(" || ");
	ft_putstr("[colle-0");
	ft_putchar('0' + idx);
	ft_putstr("] [");
	ft_putchar('0' + w);
	ft_putstr("] [");
	ft_putchar('0' + h);
	ft_putchar(']');
}

void	solve(char *input)
{
	int		i;
	int		j;
	int		count;
	int		k;
	char	*expected;

	count = 0;
	i = 0;
	while (input[i] != '\0' && input[i] != '\n')
		i++;
	j = ft_strlen(input) / (i + 1);
	k = -1;
	while (++k < 5)
	{
		expected = g_rushes[k](i, j);
		if (ft_strcmp(input, expected) == 0)
			print_answer(k, count++, i, j);
		free(expected);
	}
	if (!count)
		ft_putstr("aucune");
	ft_putchar('\n');
}

int		main(void)
{
	char	*input;

	input = ft_read_all(STDIN_FILENO);
	solve(input);
	free(input);
	return (0);
}
