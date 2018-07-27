/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 17:09:37 by dfan              #+#    #+#             */
/*   Updated: 2018/07/25 17:11:41 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void print_util(int arr[], int target_length)
{
	int i;
	int is_last;
	i = 0;
	is_last = 1;


	while (i < target_length)
	{
		if (i != arr[i] + 1) {
			is_last = 0;
		}
		ft_putchar(arr[i++] + 48);

	}

	if (is_last == 0) {
		ft_putchar(',');
	  	ft_putchar(' ');
	}

}

void  combination_rec(int partial[], int start, int index, int target_length)
{
	int i;

	i = start;
	if (index == target_length) {
		print_util(partial, target_length);
	}

	while (i <= 9)
	{
		partial[index] = i;
		combination_rec(partial, i + 1, index + 1, target_length);
		i += 1;
	}
}
void  ft_print_combn(int target_length)
{
	int partial[target_length];
	combination_rec(partial, 0, 0, target_length);
}

