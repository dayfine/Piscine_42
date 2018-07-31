/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 14:31:14 by dfan              #+#    #+#             */
/*   Updated: 2018/07/30 14:31:24 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	bytes;
	char			*p;
	char			*q;
	char			ch;

	bytes = 0;
	p = src;
	q = dest;
	while ((ch = *p++))
	{
		if (bytes + 1 < size)
		{
			*q++ = ch;
		}
		bytes++;
	}
	*q = '\0';
	return (bytes);
}
