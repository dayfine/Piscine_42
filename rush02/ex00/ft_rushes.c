/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rushes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 11:59:29 by dfan              #+#    #+#             */
/*   Updated: 2018/08/12 11:59:32 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush_core.h"

char	*rush00(int width, int height)
{
	return (rush_iter(width, height, "oooo", "-|"));
}

char	*rush01(int width, int height)
{
	return (rush_iter(width, height, "/\\\\/", "**"));
}

char	*rush02(int width, int height)
{
	return (rush_iter(width, height, "AACC", "BB"));
}

char	*rush03(int width, int height)
{
	return (rush_iter(width, height, "ACAC", "BB"));
}

char	*rush04(int width, int height)
{
	return (rush_iter(width, height, "ACCA", "BB"));
}
