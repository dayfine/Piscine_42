/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 19:36:16 by dfan              #+#    #+#             */
/*   Updated: 2018/08/02 19:36:19 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_par.h"

char		**ft_split_whitespaces(char *str);

char		*ft_strcpy_helper(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int			ft_strlen_helper(char *str)
{
	int idx;

	idx = 0;
	while (str[idx] != '\0')
		idx++;
	return (idx);
}

char		*ft_strdup_helper(char *src)
{
	char *dest;

	dest = malloc(sizeof(char) * (ft_strlen_helper(src) + 1));
	ft_strcpy_helper(dest, src);
	return (dest);
}

t_stock_par	create_arg_obj(char *arg)
{
	t_stock_par *args_obj;

	args_obj = malloc(sizeof(struct s_stock_par));
	args_obj->str = arg;
	args_obj->size_param = arg ? ft_strlen_helper(arg) : 0;
	if (arg)
	{
		args_obj->copy = ft_strdup_helper(arg);
		args_obj->tab = ft_split_whitespaces(arg);
	}
	return (*args_obj);
}

t_stock_par	*ft_param_to_tab(int ac, char **av)
{
	t_stock_par	*array;
	int			i;

	i = 0;
	array = malloc(sizeof(t_stock_par) * (ac + 1));
	while (av[i])
	{
		array[i] = create_arg_obj(av[i]);
		i++;
	}
	array[i] = create_arg_obj(0);
	return (array);
}
