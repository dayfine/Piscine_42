/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 11:52:14 by dfan              #+#    #+#             */
/*   Updated: 2018/08/07 11:52:17 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	t_list	*curr;
	int		count;

	count = 0;
	curr = begin_list;
	while (curr)
	{
		count++;
		curr = curr->next;
	}
	return (count);
}
