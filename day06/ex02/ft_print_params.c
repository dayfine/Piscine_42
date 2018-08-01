/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 16:34:44 by dfan              #+#    #+#             */
/*   Updated: 2018/07/31 16:34:46 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr2(char *str)
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

	i = 1;
	while (i < argc)
	{
		ft_putstr2(argv[i++]);
		ft_putchar('\n');
	}
	return (0);
}
