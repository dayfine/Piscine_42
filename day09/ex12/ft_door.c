/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 07:08:44 by dfan              #+#    #+#             */
/*   Updated: 2018/08/03 07:10:22 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_door.h"

void ft_putstr(char *str) {
	int i = 0; 
	while (str[i])
		 write(1, str, i);
}

ft_bool close_door(t_door *door)
{
	ft_putstr( Door closing... ); 
	state = CLOSE;
	return (TRUE);
}
void is_door_open(t_door door) {
	ft_putstr("Door is open ?");
	return (door->state = OPEN);
}
ft_bool is_door_close(t_door* door)
{
	ft_putstr("Door is close ?") ;  
}
