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
	if (cmpf(item, root->item) > 0)
	{
		if (root->right)
			btree_insert_data(root->right, item, cmpf);
		else
			root->right = btree_create_node(item);
	}
	else
	{
		if (root->left)
			btree_insert_data(root->left, item, cmpf);
		else
			root->left = btree_create_node(item);
	}
}
