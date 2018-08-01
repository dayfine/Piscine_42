/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 14:02:25 by dfan              #+#    #+#             */
/*   Updated: 2018/07/30 14:02:50 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
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
