/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 11:50:53 by dfan              #+#    #+#             */
/*   Updated: 2018/08/07 11:50:56 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"

t_list	*ft_create_list_node(char data)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node)
	{
		node->data = data;
		node->next = NULL;
	}
	return (node);
}

void	ft_list_push_back(t_list **begin_list, char data)
{
	t_list *curr;

	if (*begin_list == NULL)
	{
		*begin_list = ft_create_list_node(data);
		return ;
	}
	curr = *begin_list;
	while (curr->next)
		curr = curr->next;
	curr->next = ft_create_list_node(data);
}

char	*ft_list_to_string(t_list *begin_list, int size)
{
	t_list	*curr;
	int		i;
	char	*res;

	res = malloc(sizeof(char) * (size + 1));
	i = -1;
	curr = begin_list;
	while (++i < size)
	{
		res[i] = curr->data;
		curr = curr->next;
	}
	res[i] = '\0';
	return (res);
}

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
