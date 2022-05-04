/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:43:23 by dakim2            #+#    #+#             */
/*   Updated: 2022/05/01 18:05:36 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*re;
	int	i;

	i = 0;
	re = (int *)malloc(sizeof(int) * length);
	if (!re)
		return (NULL);
	while (i < length)
	{
		re[i] = f(tab[i]);
		i++;
	}
	return (re);
}
