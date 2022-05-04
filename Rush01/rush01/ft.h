/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 02:21:29 by dakim2            #+#    #+#             */
/*   Updated: 2022/04/24 22:29:39 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		check_input(char *str);
int		*ft_atoi(char *str);

typedef struct t_ar
{
	int	size;
	int	**array;
	int	*view;
}t_ar;
t_ar	*init_board(int size);
int		**init_array(int size);
int		init_nbr(char *str);
int		is_space(char c);

int		check_up(int **board, int *view, int index, int size);
int		check_down(int **board, int *view, int index, int size);
int		check_left(int **board, int *view, int index, int size);
int		check_right(int **board, int *view, int index, int size);
int		check(int **board, int *view, int index, int size);

#endif
