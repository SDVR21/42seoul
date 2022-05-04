/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 02:21:29 by dakim2            #+#    #+#             */
/*   Updated: 2022/04/24 03:27:30 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

void	ft_putchar(char c);
void	ft_putstr(char *str);
int	ft_strlen(char *str);
int	check_input(char *str);
int *ft_atoi(char *str);

int	check_up(int board[4][4], int view[16], int index);
int	check_down(int board[4][4], int view[16], int index);
int	check_left(int board[4][4], int view[16], int index);
int	check_right(int board[4][4], int view[16], int index);
int	check(int board[4][4], int view[16], int index);

#endif
