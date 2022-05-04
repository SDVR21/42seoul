/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 02:12:16 by dakim2            #+#    #+#             */
/*   Updated: 2022/04/24 03:54:22 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <unistd.h>

int	check_double(int board[4][4], int num, int index)
{
	int	i;

	i = 0;
	while (i < index % 4)
	{
		if (board[index / 4][i] == num)
			return (0);
		i++;
	}
	i = 0;
	while (i < index / 4)
	{
		if (board[i][index % 4] == num)
			return (0);
		i++;
	}
	return (1);
}

void	print_board(int board[4][4])
{
	int		j;
	char	c;

	j = 0;
	while (j < 16)
	{
		c = board[j / 4][j % 4] + '0';
		write(1, &c, 1);
		if (j % 4 == 3)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
		j++;
	}
}

int	solve(int board[4][4], int view[16], int in)
{
	int	n;

	n = 0;
	if (in == 16)
		return (1);
	while (++n <= 4)
	{
		if (check_double(board, n, in))
		{
			board[in / 4][in % 4] = n;
			if (check(board, view, in))
			{
				if (solve(board, view, in + 1))
					return (1);
			}
			else
				board[in / 4][in % 4] = 0;
		}
	}
	return (0);
}

#include <stdio.h>
int main(int ac, char **av)
{
	int	board[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
	int	*view;

	if (ac != 2 || !check_input(av[1]))
	{
		ft_putstr("invalid input\n");
		return (0);
	}
	view = ft_atoi(av[1]);
	if (solve(board, view, 0))
		print_board(board);
	else
		ft_putstr("find no solution\n");
	return (0);
}
