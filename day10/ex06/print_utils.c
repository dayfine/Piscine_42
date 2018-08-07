/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 19:59:24 by dfan              #+#    #+#             */
/*   Updated: 2018/08/06 19:59:25 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "print_utils.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_putstr(char *str)
{
	int idx;

	idx = 0;
	while (str[idx] != '\0')
		ft_putchar(str[idx++]);
	ft_putchar('\n');
	return (0);
}

void	ft_print_long_min(void)
{
	int i;

	i = 0;
	while (i < 20)
		ft_putchar("-9223372036854775808"[i++]);
}

int		ft_putnbr(long nb)
{
	int		i;
	char	digits[21];

	i = 0;
	if (nb == 0)
		ft_putchar('0');
	if (nb == LONG_MIN)
		ft_print_long_min();
	if (nb < 0 && nb != LONG_MIN)
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
		ft_putchar(digits[--i] + 48);
	ft_putchar('\n');
	return (0);
}
