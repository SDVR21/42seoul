/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 02:12:16 by dakim2            #+#    #+#             */
/*   Updated: 2022/04/24 22:50:52 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <unistd.h>
#include <stdlib.h>

int	check_double(int **board, int num, int index, int size)
{
	int	i;

	i = 0;
	while (i < (index % size))
	{
		if (board[index / size][i] == num)
			return (0);
		i++;
	}
	i = 0;
	while (i < (index / size))
	{
		if (board[i][index % size] == num)
			return (0);
		i++;
	}
	return (1);
}

void	print_board(int **board, int size)
{
	int		j;
	char	c;

	j = 0;
	while (j < size * size)
	{
		c = board[j / size][j % size] + '0';
		write(1, &c, 1);
		if (j % size == (size - 1))
			write(1, "\n", 1);
		else
			write(1, " ", 1);
		j++;
	}
}

int	solve(int **board, int *view, int in, int n)
{
	int	nbr;

	nbr = 0;
	if (in == 16)
		return (1);
	while (++nbr <= 4)
	{
		if (check_double(board, nbr, in, n))
		{
			board[in / n][in % n] = nbr;
			if (check(board, view, in, n))
			{
				if (solve(board, view, in + 1, n))
				{	return (1);
			
				}
			else
				board[in / n][in % n] = 0;
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_ar	*board;
	int		n;
	int		*view;

	if (ac != 2 || !check_input(av[1]))
	{
		ft_putstr("Error\n");
		return (0);
	}
	view = ft_atoi(av[1]);
	n = init_nbr(av[1]);
	if (n == 0)
	{
		ft_putstr("Error\n");
		return (0);
	}
	board = init_board(n);
	board->view = view;
	free(view);
	if (solve(board->array, board->view, 0, board->size))
		print_board(board->array, board->size);
	else
		ft_putstr("Error\n");
	print_board(board->array, board->size);
	free(board);
	return (0);
}
