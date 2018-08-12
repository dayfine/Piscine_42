/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 22:32:27 by dfan              #+#    #+#             */
/*   Updated: 2018/08/10 22:32:46 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "evals.h"

int	eval_expr(char *str)
{
	char *expr;
	char **expr_ptr;

	expr = ft_remove_spaces(str);
	expr_ptr = &expr;
	return (handle_low_order_op(expr_ptr));
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
