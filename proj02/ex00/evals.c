/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evals.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 11:20:06 by dfan              #+#    #+#             */
/*   Updated: 2018/08/11 11:20:09 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evals.h"

char	get(char **expr)
{
	char res;
	char *str;

	str = *expr;
	res = *str;
	str++;
	*expr = str;
	return (res);
}

int		num(char **expr)
{
	int res;

	res = 0;
	while (**expr >= '0' && **expr <= '9')
		res = res * 10 + (get(expr) - '0');
	return (res);
}

int		handle_num_and_group(char **expr)
{
	int res;

	if (**expr >= '0' && **expr <= '9')
		return (num(expr));
	if (**expr == '(')
	{
		get(expr);
		res = handle_low_order_op(expr);
		get(expr);
		return (res);
	}
	if (**expr == '-')
	{
		get(expr);
		return (-handle_num_and_group(expr));
	}
	return (0);
}

int		handle_high_order_op(char **expr)
{
	int		res;
	char	op;

	res = handle_num_and_group(expr);
	while (**expr == '/' || **expr == '*' || **expr == '%')
	{
		op = get(expr);
		if (op == '/')
			res /= handle_num_and_group(expr);
		else if (op == '*')
			res *= handle_num_and_group(expr);
		else if (op == '%')
			res %= handle_num_and_group(expr);
	}
	return (res);
}

int		handle_low_order_op(char **expr)
{
	int		res;
	char	op;

	res = handle_high_order_op(expr);
	while (**expr == '+' || **expr == '-')
	{
		op = get(expr);
		if (op == '+')
			res += handle_high_order_op(expr);
		else
			res -= handle_high_order_op(expr);
	}
	return (res);
}
