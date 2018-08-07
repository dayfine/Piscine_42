/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 19:59:16 by dfan              #+#    #+#             */
/*   Updated: 2018/08/06 19:59:18 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calcs.h"

static long (*op_fns[6])(long, long) = { add, sub, mul, div, mol, 0 };


long do_op(long num1, char arg2, long num2)
{
	int		i;

	i = -1;
	while (++i < 5)
	{
		if (arg2 == CALCS[i])
			return (op_fns[i](num1, num2));
	}
	return (0);
}
