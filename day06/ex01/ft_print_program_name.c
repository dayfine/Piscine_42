/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 16:34:33 by dfan              #+#    #+#             */
/*   Updated: 2018/07/31 16:34:36 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr1(char *str)
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
	if (argc > 0)
	{
		ft_putstr1(argv[0]);
		ft_putchar('\n');
	}
	return (0);
}
