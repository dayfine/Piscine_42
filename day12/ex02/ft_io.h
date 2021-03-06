/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 20:27:34 by dfan              #+#    #+#             */
/*   Updated: 2018/08/08 20:27:36 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IO_H
# define FT_IO_H

void	ft_write_from_stream_w_offset(int fd, long offset,
										int print_header, char *filename);

int		ft_write_from_file_w_offset(char *filename, long offset, \
									int print_header, int is_first);

#endif
