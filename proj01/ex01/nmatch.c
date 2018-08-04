/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmatch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 15:09:43 by dfan              #+#    #+#             */
/*   Updated: 2018/08/04 15:09:47 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen1(char *str)
{
	int idx;

	idx = 0;
	while (str[idx] != '\0')
		idx++;
	return (idx);
}

int		match_n_match(char *s, char *p, int len_s, int len_p)
{
	int i;
	int j;
	int dp[len_s + 1][len_p + 1];

	i = -1;
	while (++i < len_s + 1)
	{
		dp[i][0] = i == 0;
		j = 0;
		while (++j < len_p + 1)
		{
			if (i == 0)
				dp[i][j] = (dp[i][j - 1] && p[j - 1] == '*');
			else if (p[j - 1] != '*')
				dp[i][j] = dp[i - 1][j - 1] && s[i - 1] == p[j - 1];
			else
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
		}
	}
	return (dp[len_s][len_p]);
}

int		nmatch(char *s, char *p)
{
	return (match_n_match(s, p, ft_strlen1(s), ft_strlen1(p)));
}
