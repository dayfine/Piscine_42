/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 14:32:35 by dfan              #+#    #+#             */
/*   Updated: 2018/07/30 14:32:44 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

char	to_hex(int idx)
{
	return ("0123456789abcdef"[idx]);
}

int		is_printable_helper(char c)
{
	return (c >= 32 && c < 127);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	to_print1;
	char	to_print2;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_printable_helper(str[i]))
		{
			ft_putchar(str[i]);
		}
		else
		{
			to_print1 = to_hex(str[i] / 16);
			to_print2 = to_hex(str[i] % 16);
			ft_putchar('\\');
			ft_putchar(to_print1);
			ft_putchar(to_print2);
		}
		i++;
	}
}
