/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 09:20:25 by dfan              #+#    #+#             */
/*   Updated: 2018/08/10 09:20:27 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref, \
							int (*cmpf)(void *, void *))
{
	if (!root)
		return (NULL);
	if (cmpf(data_ref, root->item) > 0 && root->right)
		return (btree_search_item(root->right, data_ref, cmpf));
	if (cmpf(data_ref, root->item) < 0 && root->left)
		return (btree_search_item(root->left, data_ref, cmpf));
	if (cmpf(data_ref, root->item) == 0)
		return (root);
	return (NULL);
}
