/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 14:32:10 by dfan              #+#    #+#             */
/*   Updated: 2018/07/30 14:32:24 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int		ft_putchar(char c);

int		is_valid_base(char *base)
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

int 	get_char_idx(char c, char *base) {
	int i;
	i = 0;
	while (base[i] != '\0') {
		if (base[i] == c)
		{
			return i;
		}
		i++;
	}
	return -1;
}

int		ft_atoi_base(char *str, char *base)
{
	int sign;
	int curr_num;
	int i;
	int	radix;
	int char_idx;

	i = 0;
	curr_num = 0;
	sign = 1;
	radix = is_valid_base(base);
	if (str[i] == '-' || str[i] == '+')
	{
		sign = 1 - 2 * (str[i++] == '-');
	}
	while (str[i] != '\0')
	{
		if (curr_num > INT_MAX / radix)
		{
			return (sign == 1 ? INT_MAX : INT_MIN);
		}
		char_idx = get_char_idx(str[i++], base);
		if (char_idx == -1)
			return 0;
		curr_num = radix * curr_num + char_idx;
	}
	return (curr_num * sign);
}
