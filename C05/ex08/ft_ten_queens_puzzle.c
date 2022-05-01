/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 04:28:09 by dakim2            #+#    #+#             */
/*   Updated: 2022/04/25 15:55:01 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int q[10])
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = q[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_ispromising(int col, int row, int q[10])
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (q[i] == row)
			return (0);
		if (col - i == row - q[i])
			return (0);
		if (col - i == q[i] - row)
			return (0);
		i++;
	}
	return (1);
}

int	ft_ten_queen(int col, int q[10], int count)
{
	int	j;

	j = 0;
	if (col == 10)
	{
		ft_print(q);
		count++;
		return (count);
	}
	while (j < 10)
	{
		if (ft_ispromising(col, j, q))
		{
			q[col] = j;
			count = ft_ten_queen(col + 1, q, count);
		}
		j++;
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	int	q[10];
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < 10)
	{
		q[i] = -1;
		i++;
	}
	i = 0;
	while (i < 10)
	{
		q[0] = i;
		count = ft_ten_queen(1, q, count);
		i++;
	}
	return (count);
}
