/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 19:36:52 by dfan              #+#    #+#             */
/*   Updated: 2018/08/02 19:36:54 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

void	ft_putchar(char c);

void	ft_print_int_len(int nb)
{
	int		i;
	char	digits[20];

	i = 0;
	if (nb == 0)
		ft_putchar('0');
	while (nb >= 1)
	{
		digits[i++] = nb % 10;
		nb = nb / 10;
	}
	while (i > 0)
		ft_putchar(digits[--i] + 48);
	ft_putchar('\n');
}

void	ft_putline_helper(char *str)
{
	int idx;

	idx = 0;
	while (str[idx] != '\0')
		ft_putchar(str[idx++]);
	ft_putchar('\n');
}

void	ft_show_tab(t_stock_par *par)
{
	int		i;
	char	**word;

	i = 0;
	while (par[i].str)
	{
		ft_putline_helper(par[i].str);
		ft_print_int_len(par[i].size_param);
		word = par[i].tab;
		while (*word)
			ft_putline_helper(*word++);
		i++;
	}
}
