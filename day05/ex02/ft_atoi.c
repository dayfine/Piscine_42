/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 14:39:27 by dfan              #+#    #+#             */
/*   Updated: 2018/07/27 14:43:32 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int		is_white_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
			|| c == '\v' || c == '\f' || c == '\r');
}

int		ft_atoi(char *str)
{
	int sign;
	int curr_num;
	int i;

	i = 0;
	curr_num = 0;
	sign = 1;
	while (is_white_space(str[i]))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		sign = 1 - 2 * (str[i++] == '-');
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (curr_num > INT_MAX / 10)
		{
			return (sign == 1 ? INT_MAX : INT_MIN);
		}
		curr_num = 10 * curr_num + (str[i++] - '0');
	}
	return (curr_num * sign);
}
