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

int		ft_putchar(char c);

void	ft_putstr4(char *str)
{
	int idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		ft_putchar(str[idx++]);
	}
}

int		get_simple_diff_helper(char *s1, char *s2)
{
	if (s1[0] == '\0' && s2[0] == '\0')
		return (0);
	if (s1[0] == '\0')
		return (-s2[0]);
	return (s1[0]);
}

int		ft_strcmp_helper(char *s1, char *s2)
{
	int i;
	int pos_diff;
	int neg_diff;
	int sign_tick;

	i = 0;
	pos_diff = 0;
	neg_diff = 0;
	sign_tick = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		sign_tick = sign_tick == 0 ? s1[i] - s2[i] : sign_tick;
		if (s1[i] - s2[i] > 0)
			pos_diff += ((pos_diff == 0 || neg_diff == 0) ? s1[i] - s2[i] : 0);
		else if (s1[i] - s2[i] < 0)
			neg_diff += ((pos_diff == 0 || neg_diff == 0) ? s1[i] - s2[i] : 0);
		i++;
	}
	if (i == 0)
		return (get_simple_diff_helper(s1, s2));
	return (sign_tick >= 0 ? pos_diff : neg_diff);
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
	int i;

	i = 1;
	ft_sort_strings(argv, argc);
	while (i < argc)
	{
		ft_putstr4(argv[i++]);
		ft_putchar('\n');
	}
	return (0);
}
