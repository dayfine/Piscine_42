/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agauthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 16:12:25 by agauthie          #+#    #+#             */
/*   Updated: 2018/08/13 16:13:37 by agauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char a)
{
	write(STDOUT_FILENO, &a, 1);
}

void	ft_putstr_base(char *str, int stream_no)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	write(stream_no, str, len);
}

void	ft_putstr(char *str)
{
	ft_putstr_base(str, STDOUT_FILENO);
}

void	ft_puterr(char *str)
{
	ft_putstr_base(str, STDERR_FILENO);
}

void	ft_maperr(int *maperr)
{
	*maperr = 1;
	ft_puterr("map error\n");
}
