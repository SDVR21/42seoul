/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:46:28 by dakim2            #+#    #+#             */
/*   Updated: 2022/05/01 13:55:36 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *str)
{
	char	*re;
	int		l;

	l = 0;
	while (str[l])
		l++;
	re = (char *)malloc(sizeof(char) * (l + 1));
	if (!re)
		return (0);
	l = 0;
	while (str[l])
	{
		re[l] = str[l];
		l++;
	}
	re[l] = '\0';
	return (re);
}
