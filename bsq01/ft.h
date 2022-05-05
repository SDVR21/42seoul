/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 21:44:19 by dakim2            #+#    #+#             */
/*   Updated: 2022/05/04 22:10:12 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <libgen.h>

typedef struct s_map {
	char	emp;
	char	op;
	char	full;
	int		**tab;	
	int		row;
	int		col;
}t_map;

int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_puthex(unsigned char c);
int		ft_atoi(char *str);
void	error();

int		ft_strcmp(char *s1, char *s2);
void	ft_strcpy(char *dest, char *src);

typedef struct s_max_square {
	int	right_down_x;
	int	right_down_y;
	int	size;
}	t_max_square;

int	ft_min(int n1, int n2, int n3);
void	init_max_square(t_max_square *max, t_map *map);
t_max_square	*get_largest_square(t_map *map);
void	ft_print_solution(t_max_square *sq, t_map *map);

#endif
