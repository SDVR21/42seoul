/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_largest_square.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:52:22 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/05/04 22:32:49 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"

int	ft_min(int n1, int n2, int n3)
{
	int	min;

	min = n1;
	if (n2 < min)
		min = n2;
	if (n3 < min)
		min = n3;
	return (min);
}

void	init_max_square(t_max_square *max, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			if (map->tab[i][j] == 1)
				break;
			j++;
		}
		if (map->tab[i][j] == 1)
			break;
		i++;
	}
	if (i == map->row && j == map->col)
	{
		max->right_down_x = -1;
		max->right_down_y = -1;
		max->size = 0;
	}
	else
	{
		max->right_down_x = i;
		max->right_down_y = j;
		max->size = 1;
		printf("i : %d, j : %d\n", i, j);
	}
}

t_max_square	*get_largest_square(t_map *map)
{
	int				i;
	int				j;
	t_max_square	*max;

	max = (t_max_square *)malloc(sizeof(t_max_square));
	if (!max)
		return (NULL);
	init_max_square(max, map);
	i = 0;
	while (++i < map->row)
	{
		j = 0;
		while (++j < map->col)
		{
			if (map->tab[i][j])
				map->tab[i][j] += ft_min(map->tab[i - 1][j - 1], map->tab[i - 1][j], map->tab[i][j - 1]);
			if (max->size < map->tab[i][j])
			{
				max->size = map->tab[i][j];
				max->right_down_x = j;
				max->right_down_y = i;
			}
		}
	}
	return (max);
}


void	ft_print_solution(t_max_square *sq, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			if (((i > sq->right_down_y - sq->size) && (i <= sq->right_down_y)) \
				&& ((j > sq->right_down_x - sq->size) && (j <= sq->right_down_x)))
				write(1, &(map->full), 1);
			else if (map->tab[i][j] == 1)
				write(1, &(map->emp), 1);
			else
				write(1, &(map->op), 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}
