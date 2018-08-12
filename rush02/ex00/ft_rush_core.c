/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 11:57:28 by dfan              #+#    #+#             */
/*   Updated: 2018/07/28 12:41:41 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_top_bottom(int i, int h)
{
	return (i == 0 || i == h - 1);
}

char	get_corner(char corners[], int row_idx, int col_idx)
{
	if (col_idx == 0)
		return (corners[(row_idx == 0) ? 0 : 2]);
	else
		return (corners[(row_idx == 0) ? 1 : 3]);
}

char	*rush_iter(int w, int h, char corners[], char sides[])
{
	int		i;
	int		j;
	char	corner;
	char	*res;

	res = malloc(sizeof(char) * (h * (w + 1)));
	i = -1;
	while (++i < h)
	{
		j = 0;
		while (j < w)
		{
			corner = get_corner(corners, i, j);
			if (j == 0 || (j > 0 && j == w - 1))
				res[(w + 1) * i + j] = is_top_bottom(i, h) ? corner : sides[1];
			else
				res[(w + 1) * i + j] = is_top_bottom(i, h) ? sides[0] : ' ';
			j++;
		}
		res[(w + 1) * i + j] = '\n';
	}
	res[(w + 1) * h] = '\0';
	return (res);
}
