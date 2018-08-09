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

void	print_same_line_as_above()
{
	ft_putstr("*\n");
}

void	print_address(char *str)
{
	ft_putstr(str);
	ft_putstr(" ");
	free(str);
}


void	print_hex(char **hex_tab)
{
	int i;

	i = -1;
	while (++i < 16)
	{
		ft_putstr(hex_tab[i]);
		ft_putstr(" ");
		if (i == 7 || i == 15)
			ft_putstr(" ");
		free(hex_tab[i]);
	}
	free(hex_tab);
}
