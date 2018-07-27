/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 17:09:37 by dfan              #+#    #+#             */
/*   Updated: 2018/07/25 17:11:41 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_print_comb2_print_util(int result1[2], int result2[])
{
	if (!(result1[0] == result2[0] && result1[1] == result2[1]))
	{
		ft_putchar(result1[0]);
		ft_putchar(result1[1]);
		ft_putchar(' ');
		ft_putchar(result2[0]);
		ft_putchar(result2[1]);
		if (!(result1[0] == '9' && result1[1] == '8'
			&& result2[0] == '9' && result2[1] == '9'))
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
}

void	ft_print_comb2(void)
{
	int partial1[2];
	int partial2[2];

	partial1[0] = '0';
	while (partial1[0] <= '9')
	{
		partial1[1] = '0';
		while (partial1[1] <= '9')
		{
			partial2[0] = partial1[0];
			while (partial2[0] <= '9')
			{
				partial2[1] = partial1[1];
				while (partial2[1] <= '9')
				{
					ft_print_comb2_print_util(partial1, partial2);
					partial2[1]++;
				}
				partial2[0]++;
			}
			partial1[1]++;
		}
		partial1[0]++;
	}
	ft_putchar('\n');
}
