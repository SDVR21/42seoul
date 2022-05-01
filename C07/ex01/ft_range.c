/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 23:08:50 by dakim2            #+#    #+#             */
/*   Updated: 2022/05/01 13:53:05 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	len;
	int	*re;

	i = 0;
	len = max - min;
	if (min >= max)
		return (NULL);
	re = (int *)malloc(sizeof(int) * len);
	if (!re)
		return (NULL);
	while (i < len)
	{
		re[i++] = min++;
	}
	return (re);
}
