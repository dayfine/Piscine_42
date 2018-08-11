/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evals.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 11:20:10 by dfan              #+#    #+#             */
/*   Updated: 2018/08/11 11:20:12 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EVALS_H
# define FT_EVALS_H

char get(char **expr);

int	num(char **expr);

int handle_num_and_group(char **expr);

int handle_high_order_op(char **expr);

int handle_low_order_op(char **expr);

#endif
