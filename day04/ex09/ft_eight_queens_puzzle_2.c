/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 16:21:37 by dfan              #+#    #+#             */
/*   Updated: 2018/07/27 16:22:04 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_8_check_queen_helper2(int queens[], int row, int col)
{
	int idx;

	idx = 1;
	while (idx < row) {
		if (queens[idx - 1] == col
			|| idx - row ==  queens[idx - 1] - col
			|| row - idx ==  queens[idx - 1] - col)
		{
			return 0;
		}
		idx++;
	}
	return 1;
}

void	ft_8_queen_helper2(int partial[], int queen_count, int *solution_count)
{
	int i;

	if (queen_count == 8)
	{
		*solution_count = *solution_count + 1;
	}

    i = 1;
	while (i <= 8)
	{
		if (ft_8_check_queen_helper2(partial, queen_count + 1, i))
		{
			partial[queen_count] = i;
			ft_8_queen_helper2(partial, queen_count + 1, solution_count);
		}
		i++;
	}
}

int		ft_eight_queens_puzzle(void)
{
	int solution_count;
	int partial[8];

	solution_count = 0;
	ft_8_queen_helper(partial, 0, &solution_count);
	return (solution_count);
}
