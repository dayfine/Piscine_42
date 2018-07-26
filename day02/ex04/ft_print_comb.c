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

void	print_util(int arr[])
{
	int i;
	int len;
	char COMMA;
	char SPACE;

	COMMA = ',';
	SPACE = ' ';

	i = 0;
	len = sizeof(&arr)/sizeof(arr[0]) + 1;

	while (i < len)
	{
		ft_putchar(arr[i]);
		i += 1;
	}

	ft_putchar(COMMA);
	ft_putchar(SPACE);
}

void	ft_print_comb_rec(int partial[], int start, int end, int index)
{
	if (index == 3) print_util(partial);

	char arr[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	int i;
	i = start;

	while (i <= end && 3 - i <= end - i + 1)
	{
		partial[index] = arr[i];
		ft_print_comb_rec(partial, i + 1, end, index + 1);
		i += 1;
	}
}

void	ft_print_comb(void)
{
	int partial[3];
	ft_print_comb_rec(partial, 0, 9, 0);
}
