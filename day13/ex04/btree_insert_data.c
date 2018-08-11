/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 09:20:22 by dfan              #+#    #+#             */
/*   Updated: 2018/08/10 09:20:24 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item, \
							int (*cmpf)(void *, void *))
{
	t_btree *root_node;

	root_node = *root;
	if (!root_node)
	{
		*root = btree_create_node(item);
		return ;
	}
	if (cmpf(item, root_node->item) > 0)
	{
		if (root_node->right)
			btree_insert_data(&root_node->right, item, cmpf);
		else
			root_node->right = btree_create_node(item);
	}
	else
	{
		if (root_node->left)
			btree_insert_data(&root_node->left, item, cmpf);
		else
			root_node->left = btree_create_node(item);
	}
}
