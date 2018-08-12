/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush_core.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 11:59:24 by dfan              #+#    #+#             */
/*   Updated: 2018/08/12 11:59:28 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUSH_CORE_H
# define FT_RUSH_CORE_H

int		is_top_bottom(int i, int h);

char	get_corner(char corners[], int row_idx, int col_idx);

char	*rush_iter(int w, int h, char corners[], char sides[]);

#endif
