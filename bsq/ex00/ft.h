/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:11:53 by dfan              #+#    #+#             */
/*   Updated: 2018/08/13 16:31:44 by agauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# define BUF_SIZE 8192

typedef struct	s_solution
{
	char	**matrix;
	char	*symbols;
	int		width;
	int		height;
	int		max_size;
	int		max_x;
	int		max_y;
}				t_solution;

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_atoi(char *str);
char	**ft_split_whitespaces(char *str);

int		check_size(char *str);
char	*ft_read(char *filename);

#endif
