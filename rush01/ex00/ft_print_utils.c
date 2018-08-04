/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 09:33:13 by dfan              #+#    #+#             */
/*   Updated: 2018/08/04 09:33:51 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int idx;

	idx = 0;
	while (str[idx] != '\0')
		ft_putchar(str[idx++]);
}

void	ft_print_sudoku_line(char *str)
{
	int idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		ft_putchar(str[idx++]);
		ft_putchar(' ');
	}
	ft_putchar('\n');
}

void	display_error(void)
{
	ft_putstr("Error\n");
}
