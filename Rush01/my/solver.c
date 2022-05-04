/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:44:20 by dakim2            #+#    #+#             */
/*   Updated: 2022/04/24 02:56:08 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int check_case(int tab[4][4], int pos, int entry[16]);

int check_double(int board[4][4], int n, int in)
{
	int i = 0;
	while (i < in % 4)
	{
		if (board[in / 4][i] == n)
				return (0);
		i++
	}
	i = 0;
	while (i < in / 4)
	{
		if (board[i][in % 4] == n)
			return (0);
		i++;
	}
	return (1);
}

int max_height(int board[4][4], int in, int flag)
{
	int max;
	int i;
	i = 0;
	max = 0;
	if(flag) // flag == 1 : 행 검사
	{
		while (i < 4)
		{
			max = max > board[in][i] ? max : board[in][i];
			i++;
		}
	}
	else
	{
		while (i < 4)
		{
			max = max > board[i][in] ? max : board[i][in];
			i++;
		}
	}
	return max;
}

int check_row(int board[4][4], int row, int lv, int rv)
{
	int i = 0;
	int view = 0;
	int now = 0; //view
	while (i < 4)
	{
		if (now < board[row][i])
		{
			view++;
			now = board[row][i];
		} 
		i++;
	}
	if (lv == view)
		return 1;
	view = 0;
	now = 0;
	i = 3;
	while (i > -1)
	{
		if (now < board[row][i])
		{
			view++;
			now = board[row][i];
		}
		i--;
	}
	if (rv == view)
		return 1;
	return 0;
}

int check_col(int board[4][4], int col, int uv, int dv)
{
	int i = 0;
	int view = 0;
	int now = 0; //view
	while (i < 4)
	{
		if (now < board[i][col])
		{
			view++;
			now = board[i][col];
		}
		i++;
	}
	if (uv == view)
		return 1;
	view = 0;
	now = 0;
	i = 3;
	while (i > -1)
	{
		if (now < board[i][col])
		{
			view++;
			now = board[i][col];
		}
		i--;
	}
	if (dv == view)
		return 1;
	return 0;
}

//int check(int board[4][4], int view[16])
//{
//	int in
//	if ( i / 4 == 3)
//	{
//				if (check_row(board, i/4, view[(i/4)+8], view[(i/4)+12]))
//					return 1;
//	}
//	if(i %4 ==3)
//	{
//				if(check_col(board, i%4, view[i % 4], view[i % 4 + 4]))
//					return 1;
//	}
//	return 0;
//}
