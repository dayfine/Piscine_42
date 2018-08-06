/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 09:34:26 by dfan              #+#    #+#             */
/*   Updated: 2018/08/04 09:34:33 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print_utils.h"
#include "ft_sudoku_board.h"
#include "ft_sudoku_backtracking.h"

int		input_is_invalid(int argc, char **argv)
{
	int i;
	int j;

	if (argc != 10)
		return (1);
	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j])
			j++;
		if (j != 9)
			return (1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		result;
	t_board *board;

	if (input_is_invalid(argc, argv))
	{
		display_error();
		return (1);
	}
	else
	{
		argv++;
		board = create_board(argv);
		result = backtrack(board);
		if (result)
		{
			print_board(board);
			return (0);
		}
		else
		{
			display_error();
			return (1);
		}
	}
}
