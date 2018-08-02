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
	int count;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	count = max - min;
	dest = malloc(sizeof(int) * count);
	i = 0;
	while (i < count + 1)
	{
		dest[i] = min + i;
		i++;
	}
	*range = dest;
	return (count);
}
