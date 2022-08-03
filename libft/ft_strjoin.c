/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 01:55:17 by dakim2            #+#    #+#             */
/*   Updated: 2022/07/27 21:20:42 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	char	*re;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	re = malloc(sizeof(char) * (l1 + l2 + 1));
	if (!re)
		return (NULL);
	ft_strlcpy(re, s1, l1 + 1);
	ft_strlcpy(re + l1, s2, l2 + 1);
	return (re);
}
