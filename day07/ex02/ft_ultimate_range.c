/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 12:29:39 by dfan              #+#    #+#             */
/*   Updated: 2018/08/01 12:29:42 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int *dest;
	int i;
	int len;

	if (min >= max)
		return (0);
	len = max - min + 1;
	dest = malloc(sizeof(int) * len);
	i = 0;
	while (i < len) {
		dest[i] = min + i;
		i++;
	}
	*range = dest;
	return len;
}
