/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 16:34:54 by dfan              #+#    #+#             */
/*   Updated: 2018/07/31 16:34:56 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr3(char *str)
{
	int idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		ft_putchar(str[idx++]);
	}
}

int		main(int argc, char *argv[])
{
	int i;

	i = argc;
	while (--i >= 1)
	{
		ft_putstr3(argv[i]);
		ft_putchar('\n');
	}
	return (0);
}
