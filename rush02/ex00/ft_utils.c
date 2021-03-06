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
#include <limits.h>

#include "ft_str_utils.h"

#define BUFFER_SIZE 65536

void	ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

void	ft_putstr(char *str)
{
	write(STDOUT_FILENO, str, ft_strlen(str));
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

char	*ft_read_all(int fd)
{
	char	buf[BUFFER_SIZE + 1];
	int		ret;

	ret = read(fd, buf, BUFFER_SIZE);
	buf[ret] = '\0';
	return (ft_strdup(buf));
}
