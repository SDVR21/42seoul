/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 01:53:01 by dakim2            #+#    #+#             */
/*   Updated: 2022/05/01 13:53:32 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	l;
	int	*arr;

	i = 0;
	l = max - min;
	if (min >= max)
		return (0);
	arr = (int *)malloc(sizeof(int) * l);
	if (!arr)
		return (-1);
	while (i < l)
		arr[i++] = min++;
	range[0] = arr;
	return (l);
}
