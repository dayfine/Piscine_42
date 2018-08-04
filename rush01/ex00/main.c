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
#include <stdio.h>

#include "ft_print_utils.h"
#include "ft_sudoku_board.h"
#include "ft_sudoku_backtracking.h"


int		main(int argc, char **argv)
{

	t_board *board;

	if (argc != 10)
	{
		display_error();
		return (1);
	}
	argv++;
	board = create_board(argv);
	printf("---> created\n");
	print_board(board);
	printf("---> printed\n");
	backtrack(board);
	printf("---> backtracked\n");
	printf("====> Result <====\n");
	print_board(board);
	// destory_board(board);
	return (0);
}
