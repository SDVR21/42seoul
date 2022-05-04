/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 22:43:46 by dakim2            #+#    #+#             */
/*   Updated: 2022/05/01 18:06:03 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	co;
	int	i;

	co = 0;
	i = 0;
	while (i < length)
	{
		if (f(tab[i]) != 0)
			co++;
		i++;
	}
	return (co);
}
