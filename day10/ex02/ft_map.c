/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 19:35:05 by dfan              #+#    #+#             */
/*   Updated: 2018/08/06 19:35:45 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int i;
	int *res;

	i = -1;
	res = malloc(sizeof(int) * length);
	while (++i < length)
		res[i] = f(tab[i]);
	return (res);
}
