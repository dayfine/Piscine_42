/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 11:52:38 by dfan              #+#    #+#             */
/*   Updated: 2018/08/07 11:52:39 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*curr;
	t_list	*prev;
	int		i;

	i = -1;
	prev = NULL;
	curr = NULL;
	while (++i < ac)
	{
		curr = ft_create_elem(av[i]);
		curr->next = prev;
		prev = curr;
	}
	return (curr);
}
