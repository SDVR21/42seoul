/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_largest_square.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:52:22 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/05/04 16:00:17 by hyeyukim         ###   ########.fr       */
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

int	init_max_square(t_max_square *max)
{
	max->right_down_x = -1;
	max->right_down_y = -1;
	max->size = -1;
}

t_max_square	*get_largest_square(t_map *map)
{
	t_max_square	*max;
	int				i;
	int				j;

	max = (t_max_square *)malloc(sizeof(t_max_square));
	if (!max)
		return (0);
	init_max_square(max);
	j = -1;
	while (++j < map->col)
	{
		i = -1;
		while (++i < map->row)
		{
			map->tab[i][j] += ft_min(map->tab[i - 1][j - 1], \
								map->tab[i - 1][j],\
								map->tab[i][j - 1]);
			if (max->size < map->tab[i][j])
			{
				max->size = map->tab[i][j];
				max->right_down_x = i;
				max->right_down_y = j;
			}
		}
	}
	return (max);
}

