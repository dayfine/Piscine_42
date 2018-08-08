/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 11:53:12 by dfan              #+#    #+#             */
/*   Updated: 2018/08/07 11:53:12 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, \
						void (*f)(void *), void *data_ref, int (*cmp)())
{
	t_list	*curr;

	curr = begin_list;
	while (curr)
	{
		if (cmp(curr->data, data_ref) == 0)
			f(curr->data);
		curr = curr->next;
	}
}
