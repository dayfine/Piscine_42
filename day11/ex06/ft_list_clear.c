/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 11:52:47 by dfan              #+#    #+#             */
/*   Updated: 2018/08/07 11:52:48 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	free_list_helper(t_list *head)
{
	if (!head)
		return ;
	free_list_helper(head->next);
	free(head);
}

void	ft_list_clear(t_list **begin_list)
{
	if (*begin_list == NULL)
		return ;
	free_list_helper(*begin_list);
	*begin_list = NULL;
}
