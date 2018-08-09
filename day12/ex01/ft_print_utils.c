/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 15:11:19 by dfan              #+#    #+#             */
/*   Updated: 2018/08/09 15:11:21 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

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
