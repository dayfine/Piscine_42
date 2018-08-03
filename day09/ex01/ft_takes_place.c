/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 07:17:11 by dfan              #+#    #+#             */
/*   Updated: 2018/08/03 07:17:27 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_takes_place(int hour)
{
	int		next;
	char	h_ap;
	char	n_ap;

	next = (hour + 1) % 24;
	h_ap = (hour > 11 && hour < 24) ? 'P' : 'A';
	n_ap = (next > 11 && next < 24) ? 'P' : 'A';
	if (hour == 0)
		hour = 12;
	else
		hour = hour > 12 ? hour - 12 : hour;
	if (next == 0)
		next = 12;
	else
		next = next > 12 ? next - 12 : next;
	printf("THE FOLLOWING TAKES PLACE BETWEEN %d.00 %c.M. AND %d.00 %c.M.",
			hour, h_ap, next, n_ap);
}
