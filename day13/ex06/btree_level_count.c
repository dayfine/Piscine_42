/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 09:20:29 by dfan              #+#    #+#             */
/*   Updated: 2018/08/10 09:20:31 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int		btree_level_count(t_btree *root)
{
	int left_count;
	int	right_count;

	if (root == NULL)
		return (0);
	left_count = btree_level_count(root->left);
	right_count = btree_level_count(root->right);
	return (1 + (left_count > right_count ? left_count : right_count));
}
