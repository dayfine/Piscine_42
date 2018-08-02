/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 12:30:06 by dfan              #+#    #+#             */
/*   Updated: 2018/08/01 12:30:20 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen_helper(char *str)
{
	int idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		idx++;
	}
	return (idx);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		char_counts;
	int		i;
	int		j;
	int		k;
	char	*dest;

	i = 1;
	char_counts = 0;
	while (i < argc)
	{
		char_counts += ft_strlen_helper(argv[i]);
		char_counts += (i++ != argc - 1);
	}
	dest = malloc(sizeof(char) * (char_counts + 1));
	i = 1;
	k = 0;
	while (i < argc)
	{
		j = 0;
		while (j < ft_strlen_helper(argv[i]))
			dest[k++] = argv[i][j++];
		if (i++ != argc - 1)
			dest[k++] = '\n';
	}
	return (dest);
}
