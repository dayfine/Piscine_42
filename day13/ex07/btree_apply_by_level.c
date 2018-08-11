/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 09:20:32 by dfan              #+#    #+#             */
/*   Updated: 2018/08/10 09:20:33 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

int		ft_power(int nb, int power)
{
	int res;

	res = 1;
	if (power < 0)
		return (0);
	if (power == 0 || nb == 1)
		return (1);
	while (power-- > 0)
		res *= nb;
	return (res);
}

t_btree	**apply_level_n_make_next_level(t_btree **level, int level_no, \
			void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int		i;
	int		j;
	t_btree **next_level;

	next_level = malloc(sizeof(t_btree) * (ft_power(2, level_no + 1) + 1));
	i = -1;
	j = 0;
	while (level[++i])
	{
		applyf(level[i]->item, level_no, i == 0);
		if (level[i]->left)
			next_level[j++] = level[i]->left;
		if (level[i]->right)
			next_level[j++] = level[i]->right;
	}
	next_level[j] = NULL;
	free(level);
	return (next_level);
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item, \
							int current_level, int is_first_elem))
{
	int		level_no;
	t_btree **level;
	t_btree **next_level;

	level_no = 0;
	level = malloc(sizeof(t_btree) * (ft_power(2, level_no) + 1));
	level[0] = root;
	level[1] = NULL;
	while (root && *level)
	{
		next_level = apply_level_n_make_next_level(level, level_no, applyf);
		level_no++;
		level = next_level;
	}
	free(next_level);
}
