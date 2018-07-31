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


/* It will then NUL-terminate, unless dstsize is 0 or the original dst string
     was longer than dstsize */
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	bytes;
	char			*p;
	char			*q;
	char			ch;
	unsigned		orig_len;

	bytes = 0;
	p = src;
	q = dest;
	while (bytes < size && *q)
	{
		q++;
		bytes++;
	}
	orig_len = bytes + 1;
	while ((ch = *p++))
	{
		if (bytes + 1 < size)
		{
			*q++ = ch;
		}
		bytes++;
	}
	if (!(size == 0 || orig_len > size))
		*q = '\0';
	return (bytes);
}
