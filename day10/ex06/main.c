/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 19:50:18 by dfan              #+#    #+#             */
/*   Updated: 2018/08/06 19:50:20 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_utils.h"
#include "num_utils.h"
#include "ops.h"

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (1);
	if (argv[2][1])
		return (ft_putnbr(0));
	if (ft_atoi(argv[3]) == 0 && argv[2][0] == '/')
		return (ft_putstr("Stop : division by zero"));
	if (ft_atoi(argv[3]) == 0 && argv[2][0] == '%')
		return (ft_putstr("Stop : modulo by zero"));
	ft_putnbr(do_op(ft_atoi(argv[1]), argv[2][0], ft_atoi(argv[3])));
	return (0);
}
