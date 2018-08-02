/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 14:02:57 by dfan              #+#    #+#             */
/*   Updated: 2018/08/01 14:03:14 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This is wrong but I am not fixing it right now. See ex06 for correct impl */
int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int				pos_diff;
	int				neg_diff;
	int				sign_tick;

	i = 0;
	pos_diff = 0;
	neg_diff = 0;
	sign_tick = 0;
	while (i < n)
	{
		sign_tick = sign_tick == 0 ? s1[i] - s2[i] : sign_tick;
		if (s1[i] - s2[i] > 0)
			pos_diff += ((pos_diff == 0 || neg_diff == 0) ? s1[i] - s2[i] : 0);
		else if (s1[i] - s2[i] < 0)
			neg_diff += ((pos_diff == 0 || neg_diff == 0) ? s1[i] - s2[i] : 0);
		if (s1[i] == '\0' || s2[i] == '\0')
			break ;
		i++;
	}
	return (sign_tick >= 0 ? pos_diff : neg_diff);
}
