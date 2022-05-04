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

int	check_up(int board[4][4], int view[16], int index)
{
	int	i;
	int	max;
	int	now;

	i = 0;
	max = 0;
	now = 0;
	if (index / 4 == 3)
	{
		while (i < 4)
		{
			if (board[i][index % 4] > max)
			{
				max = board[i][index % 4];
				now++;
			}
			i++;
		}
		if (view[index % 4] != now)
			return (1);
	}
	return (0);
}

int	check_right(int board[4][4], int view[16], int index)
{
	int	i;
	int	max;
	int	now;

	i = 4;
	max = 0;
	now = 0;
	if (index % 4 == 3)
	{
		while (--i >= 0)
		{
			if (board[index / 4][i] > max)
			{
				max = board[index / 4][i];
				now++;
			}
		}
		if (view[12 + index / 4] != now)
			return (1);
	}
	return (0);
}

int	check_down(int board[4][4], int view[16], int index)
{
	int	i;
	int	max;
	int	now;

	i = 3;
	max = 0;
	now = 0;
	if (index / 4 == 3)
	{
		while (i >= 0)
		{
			if (board[i][index % 4] > max)
			{
				max = board[i][index % 4];
				now++;
			}
			i--;
		}
		if (view[4 + index % 4] != now)
			return (1);
	}
	return (0);
}

int	check_left(int board[4][4], int view[16], int index)
{
	int	i;
	int	max;
	int	now;

	i = 0;
	max = 0;
	now = 0;
	if (index % 4 == 3)
	{
		while (i < 4)
		{
			if (board[index / 4][i] > max)
			{
				max = board[index / 4][i];
				now++;
			}
			i++;
		}
		if (view[8 + index / 4] != now)
			return (1);
	}
	return (0);
}

int	check(int board[4][4], int view[16], int index)
{
	if (check_left(board, view, index))
		return (0);
	if (check_right(board, view, index))
		return (0);
	if (check_up(board, view, index))
		return (0);
	if (check_down(board, view, index))
		return (0);
	return (1);
}
