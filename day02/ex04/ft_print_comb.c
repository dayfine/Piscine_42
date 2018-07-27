/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 17:09:37 by dfan              #+#    #+#             */
/*   Updated: 2018/07/25 17:11:41 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	comb_print_util(int result[])
{
	ft_putchar(result[0]);
	ft_putchar(result[1]);
	ft_putchar(result[2]);
	if (!(result[0] == '7' && result[1] == '8' && result[2] == '9'))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	int partial[3];

	partial[0] = '0';
	while (partial[0] <= '9')
	{
		partial[1] = partial[0] + 1;
		while (partial[1] <= '9')
		{
			partial[2] = partial[1] + 1;
			while (partial[2] <= '9')
			{
				comb_print_util(partial);
				partial[2]++;
			}
			partial[1]++;
		}
		partial[0]++;
	}
	ft_putchar('\n');
}
