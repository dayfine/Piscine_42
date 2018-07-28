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

int		ft_putchar(char c);

void	ft_putnbr(int nb)
{
	int		i;
	char	digits[20];

	if (nb == 0)
	{
		ft_putchar('0');
	}
	else
	{
		if (nb < 0)
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
}
