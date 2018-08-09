/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 22:04:05 by dfan              #+#    #+#             */
/*   Updated: 2018/08/08 22:04:06 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
}

void	print_ascii(char *str)
{
	int		i;
	char	to_print;

	ft_putstr("|");
	i = -1;
	while (str[++i])
	{
		to_print = (str[i] == '\n' || str[i] == '\t') ? '.' : str[i];
		write(1, &to_print, 1);
	}
	ft_putstr("|\n");
}

void	print_same_line_as_above(void)
{
	ft_putstr("*\n");
}

void	print_address(long addr)
{
	int		i;
	char	digits[32];
	char	*str;

	str = malloc(sizeof(char) * 9);
	i = -1;
	while (++i < 8)
		str[i] = '0';
	str[8] = '\0';
	i = 0;
	while (addr >= 1)
	{
		digits[i++] = "0123456789abcdef"[addr % 16];
		addr = addr / 16;
	}
	while (--i >= 0)
		str[7 - i] = digits[i];
	ft_putstr(str);
	ft_putstr(" ");
	free(str);
}

void	print_hex(char *str)
{
	int		i;
	int		ended;
	char	to_print;

	i = -1;
	ended = 0;
	while (++i < 16)
	{
		if (!str[i])
			ended = 1;
		if (!ended)
		{
			to_print = "0123456789abcdef"[str[i] / 16];
			write(1, &to_print, 1);
			to_print = "0123456789abcdef"[str[i] % 16];
			write(1, &to_print, 1);
		}
		else
		{
			ft_putstr("  ");
		}
		ft_putstr(" ");
		if (i == 7 || i == 15)
			ft_putstr(" ");
	}
}
