/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 14:51:54 by dfan              #+#    #+#             */
/*   Updated: 2018/08/08 14:51:55 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_utils.h"
#include "ft_io.h"

int		main(int argc, char *argv[])
{
	int		i;
	long	offset;

	if (argc < 4)
	{
		ft_write_from_stream(STDIN_FILENO);
		return (1);
	}
	offset = ft_atoi_neg_offset(argv[2]);
	i = 2;
	while (++i < argc)
		ft_write_from_file_w_offset(argv[i], offset, argc > 4, i == 3);
	return (0);
}
