/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:34:07 by dakim2            #+#    #+#             */
/*   Updated: 2022/04/24 22:49:14 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>

t_ar	*init_board(int size)
{
	int		*view;
	t_ar	*board;

	board = (t_ar *)malloc(sizeof(t_ar));
	board->size = size;
	view = (int *)malloc(sizeof(int) * (size * size));
	board->view = view;
	board->array = init_array(size);
	free(view);
	return (board);
}

int	**init_array(int size)
{
	int		*row;
	int		i;
	int		j;
	int		**array;

	i = 0;
	array = (int **)malloc(sizeof(int *) * size);
	while (i < size)
	{
		j = 0;
		row = (int *)malloc(sizeof(int) * size);
		while (j < size)
			row[j++] = 0;
		array[i] = row;
		i++;
		free(row);
	}
	return (array);
}

int	init_nbr(char *str)
{
	int		i;
	int		size;
	int		len;

	size = 0;
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '9')
			len++;
		i++;
	}
	i = 4;
	while (i < 10)
	{
		if (i * 4 == len)
			size = i;
		i++;
	}
	return (size);
}

int	is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}
