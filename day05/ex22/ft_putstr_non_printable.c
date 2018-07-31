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

void	print_hex(int idx)
{
	unsigned int	u_idx;

	u_idx = idx < 0 ? (unsigned int)(idx + 256) : (unsigned int)idx;
	ft_putchar("0123456789abcdef"[u_idx / 16]);
	ft_putchar("0123456789abcdef"[u_idx % 16]);
}

int		is_printable_helper(char c)
{
	return (c >= 32 && c < 127);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_printable_helper(str[i]))
		{
			ft_putchar(str[i]);
		}
		else
		{
			ft_putchar('\\');
			print_hex(str[i]);
		}
		i++;
	}
}
