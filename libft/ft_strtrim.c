/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 03:01:31 by dakim2            #+#    #+#             */
/*   Updated: 2022/07/29 01:15:57 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;

	s2 = (char *)s1 + (ft_strlen(s1) - 1);
	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	while (s2 >= s1 && ft_strchr(set, *s2))
		s2--;
	return (ft_substr(s1, 0, s2 - s1 + 1));
}
