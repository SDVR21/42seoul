/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 02:52:32 by dakim2            #+#    #+#             */
/*   Updated: 2022/04/24 03:51:37 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_up(int **board, int *view, int index, int size)
{
	int	i;
	int	max;
	int	now;

	i = 0;
	max = 0;
	now = 0;
	if (index / size == (size - 1))
	{
		while (i < size)
		{
			if (board[i][index % size] > max)
			{
				max = board[i][index % size];
				now++;
			}
			i++;
		}
		if (view[index % size] != now)
			return (1);
	}
	return (0);
}

int	check_right(int **board, int *view, int index, int size)
{
	int	i;
	int	max;
	int	now;

	i = size - 1;
	max = 0;
	now = 0;
	if (index % size == (size - 1))
	{
		while (i >= 0)
		{
			if (board[index / size][i] > max)
			{
				max = board[index / size][i];
				now++;
			}
			i--;
		}
		if (view[12 + index / size] != now)
			return (1);
	}
	return (0);
}

int	check_down(int **board, int *view, int index, int size)
{
	int	i;
	int	max;
	int	now;

	i = size - 1;
	max = 0;
	now = 0;
	if (index / size == (size - 1))
	{
		while (i >= 0)
		{
			if (board[i][index % size] > max)
			{
				max = board[i][index % size];
				now++;
			}
			i--;
		}
		if (view[4 + index % size] != now)
			return (1);
	}
	return (0);
}

int	check_left(int **board, int *view, int index, int size)
{
	int	i;
	int	max;
	int	now;

	i = 0;
	max = 0;
	now = 0;
	if (index % size == (size - 1))
	{
		while (i < size)
		{
			if (board[index / size][i] > max)
			{
				max = board[index / size][i];
				now++;
			}
			i++;
		}
		if (view[8 + index / size] != now)
			return (1);
	}
	return (0);
}

int	check(int **board, int *view, int index, int size)
{
	if (check_left(board, view, index, size))
		return (0);
	if (check_right(board, view, index, size))
		return (0);
	if (check_up(board, view, index, size))
		return (0);
	if (check_down(board, view, index, size))
		return (0);
	return (1);
}
