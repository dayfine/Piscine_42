/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 16:35:04 by dfan              #+#    #+#             */
/*   Updated: 2018/07/31 16:35:08 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr4(char *str)
{
	int idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		ft_putchar(str[idx++]);
	}
}

int		ft_strcmp_helper(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] - s2[i] != 0)
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_sort_strings(char *strings[], int size)
{
	int		i;
	int		j;
	char	*key;

	i = 1;
	while (i < size)
	{
		key = strings[i];
		j = i - 1;
		while (j >= 0 && ft_strcmp_helper(strings[j], key) > 0)
		{
			strings[j + 1] = strings[j];
			j--;
		}
		strings[j + 1] = key;
		i++;
	}
}

int		main(int argc, char *argv[])
{
	int		i;
	char	*program_name;

	i = 0;
	program_name = argv[0];
	ft_sort_strings(argv, argc);
	while (i < argc)
	{
		if (ft_strcmp_helper(argv[i], program_name) != 0)
		{
			ft_putstr4(argv[i]);
			ft_putchar('\n');
		}
		i++;
	}
	return (0);
}
