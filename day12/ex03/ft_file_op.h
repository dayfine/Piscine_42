/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_op.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 15:11:19 by dfan              #+#    #+#             */
/*   Updated: 2018/08/09 15:11:21 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_OP_H
# define FT_FILE_OP_H

typedef void	(*t_file_op) (int fd);

int		handle_fd_errors(char *program, char *filename);

int		ft_perform_file_op(char *program, char *filename, t_file_op write_op);

#endif
