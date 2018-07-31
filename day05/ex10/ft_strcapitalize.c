/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 14:06:05 by dfan              #+#    #+#             */
/*   Updated: 2018/07/30 14:06:08 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_alphanumeric(char c)
{
	return ((c >= '0' && c <= '9')
			|| (c >= 'a' && c <= 'z')
			|| (c >= 'A' && c <= 'Z'));
}

char	to_lower(char c)
{
	return (c >= 'A' && c <= 'Z') ? c + 32 : c;
}

char	to_upper(char c)
{
	return (c >= 'a' && c <= 'z') ? c - 32 : c;
}

char	*ft_strcapitalize(char *str)
{
	int i;
	int j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0' && is_alphanumeric(str[i + j]))
		{
			str[i + j] = j == 0 ? to_upper(str[i + j]) : to_lower(str[i + j]);
			j++;
		}
		i += j == 0 ? 1 : j;
	}
	return (str);
}
