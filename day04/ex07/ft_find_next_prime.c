/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 16:21:37 by dfan              #+#    #+#             */
/*   Updated: 2018/07/28 09:01:27 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime_helper(int nb)
{
	int trial;

	trial = 2;
	if (nb < 2)
	{
		return (0);
	}
	while (trial * trial <= nb)
	{
		if (nb % trial == 0)
		{
			return (0);
		}
		trial++;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	if (nb <= 2)
	{
		return (2);
	}
	while (!ft_is_prime_helper(nb))
	{
		nb++;
	}
	return (nb);
}
