/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 14:51:54 by dfan              #+#    #+#             */
/*   Updated: 2018/08/08 14:51:55 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

#include "ft_io.h"

int		is_white_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
			|| c == '\v' || c == '\f' || c == '\r');
}

long	ft_atoi_neg_offset(char *str)
{
	long		sign;
	long		curr_num;
	int			i;

	i = 0;
	curr_num = 0;
	sign = 1;
	while (is_white_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = 1 - 2 * (str[i++] == '-');
	else
		sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (curr_num > LONG_MAX / 10)
			return (sign == 1 ? LONG_MAX : LONG_MIN);
		curr_num = 10 * curr_num + (str[i++] - '0');
	}
	return (curr_num * sign);
}

int		main(int argc, char *argv[])
{
	int		i;
	long	offset;

	i = 2;
	offset = ft_atoi_neg_offset(argv[2]);
	if (argc <= 3)
		ft_write_from_stream_w_offset(STDIN_FILENO, offset, 0, 0);
	while (++i < argc)
		ft_write_from_file_w_offset(argv[i], offset, argc > 4, i == 3);
	return (0);
}
