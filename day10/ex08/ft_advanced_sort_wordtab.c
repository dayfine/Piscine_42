/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_wordtab.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 09:33:55 by dfan              #+#    #+#             */
/*   Updated: 2018/08/07 09:33:57 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_wordtab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	char	*key;

	i = 0;
	while (tab[++i])
	{
		key = tab[i];
		j = i;
		while (--j >= 0 && cmp(tab[j], key) > 0)
			tab[j + 1] = tab[j];
		tab[j + 1] = key;
	}
}
