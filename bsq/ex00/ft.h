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

typedef void	(*t_file_op) (int fd);

typedef struct	s_list
{
	struct s_list	*next;
	char			data;
}				t_list;

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

void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_puterr(char *str);
void			ft_maperr(void);

void			ft_list_push_back(t_list **begin_list, char data);
char			*ft_list_to_string(t_list *begin_list, int size);
void			ft_list_clear(t_list **begin_list);

int				ft_perform_file_op(char *program, char *filename, \
									t_file_op file_op);
void			ft_bsq_map_op(int fd);

t_solution		*create_solution(char **matrix, char *symbols, int w, int h);
void			destroy_board(t_solution *s);
void			update_solution(t_solution *s, int size, int x, int y);
void			apply_solution(t_solution *s);
void			print_board(t_solution *s);

void			find_bsq(t_solution *s);

#endif
