/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 12:30:30 by dfan              #+#    #+#             */
/*   Updated: 2018/08/01 12:30:49 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		includes(char *str, char letter)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i++] == letter)
		{
			return (1);
		}
	}
	return (0);
}

int		get_word_count(char *str, char *breaks)
{
	int i;
	int wc;

	i = 0;
	wc = 0;
	if (str[0] == '\0') {
		return (0);
	}

	while (str[i + 1] != '\0')
	{
		if (i == 0 && !includes(breaks, str[i]))
		{
			wc++;
		}
		else if (includes(breaks, str[i]) && !includes(breaks, str[i + 1]))
		{
			wc++;
		}
		i++;
	}
	return (wc);
}

char	**ft_split(char *str, char *breaks, int word_count)
{
	int i;
	int j;
	int k;
	int word_len;
	char **dest;
	char null[1];

	dest = malloc(sizeof(char*) * (word_count + 1));
	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		while (includes(breaks, str[i++])) ;
		word_len = 0;
		i -= i != 0;
		printf("%d\n", i);
		while (str[i + word_len] && !includes(breaks, str[i + word_len]))
			word_len++;
		j = 0;
		dest[k] = malloc((word_len + 1) * sizeof(char));
		while (j < word_len)
			dest[k][j++] = str[i++];
		dest[k][j] = '\0';
		k++;
	}
	dest[k] = null;
	return (dest);
}

char	**ft_split_whitespaces(char *str)
{
	int word_count;

	word_count = get_word_count(str, " \t\n");
	return (ft_split(str, " \t\n", word_count));
}
