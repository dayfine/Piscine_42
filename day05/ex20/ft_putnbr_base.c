/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 14:31:42 by dfan              #+#    #+#             */
/*   Updated: 2018/07/30 14:31:50 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		is_valid_base2(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i] != '\0')
	{
		j = 0;
		while (base[j] != '\0')
		{
			if (base[i] == base[j] && i != j)
			{
				return (0);
			}
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
		{
			return (0);
		}
		i++;
	}
	return (i > 1 ? i : 0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		radix;
	int		i;
	char	digits[50];

	radix = is_valid_base2(base);
	if (radix == 0)
		return ;
	i = 0;
	if (nbr == 0)
	{
		ft_putchar(base[0]);
		return ;
	}
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-');
	}
	while (nbr >= 1)
	{
		digits[i++] = base[nbr % radix];
		nbr = nbr / radix;
	}
	while (i > 0)
		ft_putchar(digits[--i]);
}
