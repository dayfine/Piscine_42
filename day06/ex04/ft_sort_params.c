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
	if (sign_tick == 0)
		return (s1[i] - s2[i]);
	return (sign_tick > 0 ? pos_diff : neg_diff);
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

	i = 1;
	program_name = argv[0];
	ft_sort_strings(argv, argc);
	while (i < argc)
	{
		if (ft_strcmp_helper(argv[i], program_name) != 0)
		{
			ft_putstr4(argv[i++]);
			ft_putchar('\n');
		}
	}
	return (0);
}
