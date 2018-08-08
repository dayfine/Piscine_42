/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 11:51:13 by dfan              #+#    #+#             */
/*   Updated: 2018/08/07 11:51:54 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *curr;

	if (*begin_list == NULL)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	curr = *begin_list;
	while (curr->next)
		curr = curr->next;
	curr->next = ft_create_elem(data);
}
