/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 12:31:31 by dfan              #+#    #+#             */
/*   Updated: 2018/08/01 12:31:42 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int		ft_strlen(char *str)
{
	int idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		idx++;
	}
	return (idx);
}

int		get_char_idx(char c, char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int	parse_int(char *nbr, char *base_from)
{
	int sign;
	int i;
	int num;
	int char_idx;
	int	radix;

	i = 0;
	num = 0;
	sign = 1;
	radix = ft_strlen(base_from);
	if (nbr[0] == '-' || nbr[0] == '+')
		sign = 1 - 2 * (nbr[i++] == '-');
	while (nbr[i] != '\0')
	{
		char_idx = get_char_idx(nbr[i++], base_from);
		if (num > INT_MAX / radix
			|| (num == INT_MAX / radix && char_idx > INT_MAX % radix))
			return (sign == 1 ? INT_MAX : INT_MIN);
		if (char_idx == -1)
			return (0);
		num = radix * num + char_idx;
	}
	return (num * sign);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				radix;
	int				i;
	unsigned int	abs_n;
	char			digits[50];

	radix = ft_strlen(base);
	if (radix == 0)
		return ;
	i = 0;
	if (nbr == 0)
	{
		ft_putchar(base[0]);
		return ;
	}
	if (nbr < 0)
		ft_putchar('-');
	abs_n = nbr < 0 ? -((unsigned int)(nbr)) : (unsigned int)(nbr);
	while (abs_n >= 1)
	{
		digits[i++] = base[abs_n % radix];
		abs_n = abs_n / radix;
	}
	while (i > 0)
		ft_putchar(digits[--i]);
	ft_putchar('\n');
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int number;
	int curr_num;
	int i;
	int	radix1;
	int	radix2;
	int char_idx;

	printf("\n%d --", parse_int(nbr, base_from));
	ft_putnbr_base(parse_int(nbr, base_from), base_to);
}
