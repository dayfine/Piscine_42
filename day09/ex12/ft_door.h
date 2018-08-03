/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 07:08:37 by dfan              #+#    #+#             */
/*   Updated: 2018/08/03 07:08:40 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DOOR_H
# define FT_DOOR_H

# define OPEN 1
# define CLOSE 0
# define EXIT_SUCCESS 0

# include <unistd.h>

typedef int		t_bool;

typedef struct	s_door
{
	t_bool	state;
}				t_door;

#endif
