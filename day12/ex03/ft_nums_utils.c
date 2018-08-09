/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nums_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 22:04:01 by dfan              #+#    #+#             */
/*   Updated: 2018/08/08 22:04:02 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *byte_to_hex(char c) {
	c = c < 0 ? (unsigned char)(c + 256) : (unsigned char)c;
	ft_putchar("0123456789abcdef"[u_idx / 16]);
	ft_putchar("0123456789abcdef"[u_idx % 16]);
}

char *get_hex_address(long addr)
{
	int		i;
	char	digits[32];
	char	*res;

	res = malloc(sizeof(char) * 9);
	i = -1;
	while (++i < 8)
		res[i] = '0';
	res[8] = '\0';
	i = 0;
	while (addr >= 1)
	{
		digits[i++] = "0123456789abcdef"[addr % 16];
		addr = addr / 16;
	}
	while (--i >= 0)
		res[7 - i] = digits[i];
	return (res);
}
