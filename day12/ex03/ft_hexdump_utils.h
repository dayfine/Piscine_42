/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump_utils.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 22:04:12 by dfan              #+#    #+#             */
/*   Updated: 2018/08/08 22:04:14 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_UTILS_H
# define FT_HEXDUMP_UTILS_H

void	print_address(long addr);

void	hexdump_line(long addr, char *buf, int print, int *repeat_printed);

#endif
