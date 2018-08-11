/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 15:11:19 by dfan              #+#    #+#             */
/*   Updated: 2018/08/09 15:11:21 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

void	ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

void	ft_putstr(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	write(STDOUT_FILENO, str, len);
}

void	ft_putnbr(int nb)
{
	int		i;
	char	digits[20];

	i = 0;
	if (nb == 0)
		ft_putchar('0');
	if (nb == INT_MIN)
		ft_putstr("-2147483648");
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
		ft_putchar(digits[--i] + '0');
}

char	*ft_remove_spaces(char *str)
{
	int		i;
	int		j;
	int		count;
	char	*res;

	i = -1;
	count = 0;
	while (str[++i])
		count += (str[i] != ' ' && str[i] != '\t');
	res = malloc(sizeof(char) * (count + 1));
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			res[j++] = str[i];
	}
	res[j] = '\0';
	return (res);
}

int		ft_atoi(char *str)
{
	int sign;
	int curr_num;
	int i;

	i = 0;
	curr_num = 0;
	sign = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = 1 - 2 * (str[i++] == '-');
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (curr_num > INT_MAX / 10)
			return (sign == 1 ? INT_MAX : INT_MIN);
		curr_num = 10 * curr_num + (str[i++] - '0');
	}
	return (curr_num * sign);
}

