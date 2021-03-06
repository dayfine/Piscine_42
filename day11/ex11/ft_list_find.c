/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 11:53:17 by dfan              #+#    #+#             */
/*   Updated: 2018/08/07 11:53:17 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list	*curr;

	curr = begin_list;
	while (curr)
	{
		if (cmp(curr->data, data_ref) == 0)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}
