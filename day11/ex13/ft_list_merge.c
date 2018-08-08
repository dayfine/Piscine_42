/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 11:53:28 by dfan              #+#    #+#             */
/*   Updated: 2018/08/07 11:53:29 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *curr;

	if (begin_list2 == NULL)
		return ;
	if (*begin_list1 == NULL)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	curr = *begin_list1;
	while (curr && curr->next)
		curr = curr->next;
	curr->next = begin_list2;
}
