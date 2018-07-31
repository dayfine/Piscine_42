/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 17:09:37 by dfan              #+#    #+#             */
/*   Updated: 2018/07/26 23:05:58 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int		ft_putchar(char c);

void	ft_print_int_min(void)
{
	int i;

	i = 0;
	while (i < 11)
		ft_putchar("-2147483648"[i++]);
}

void	ft_putnbr(int nb)
{
	int		i;
	char	digits[20];

	i = 0;
	if (nb == 0)
		ft_putchar('0');
	if (nb == INT_MIN)
		ft_print_int_min();
	if (nb < 0 && nb != INT_MIN)
	{
		nb = -nb;
		ft_putchar('-');
	}
	while (nb >= 1)
	{
		digits[i++] = nb % 10;
		nb = nb / 10;
	}
	while (i > 0)
	{
		ft_putchar(digits[--i] + 48);
	}
}
