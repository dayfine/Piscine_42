/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 11:53:23 by dfan              #+#    #+#             */
/*   Updated: 2018/08/07 11:53:24 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_remove_rec(t_list *head, void *data_ref, int (*cmp)())
{
	if (head == NULL)
		return (NULL);

	if (cmp(head->data, data_ref) == 0)
		return (ft_list_remove_rec(head->next, data_ref, cmp));

	head->next = ft_list_remove_rec(head->next, data_ref, cmp);
	return (head);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	*begin_list = ft_list_remove_rec(*begin_list, data_ref, cmp);
}
