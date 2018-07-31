/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 14:30:52 by dfan              #+#    #+#             */
/*   Updated: 2018/07/30 14:31:04 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	bytes;
	char			*p;
	char			*q;
	char			ch;

	bytes = 0;
	p = src;
	q = dest;
	while (bytes < size && *q)
	{
		q++;
		bytes++;
	}
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
