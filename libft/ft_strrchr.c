/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 21:47:21 by dakim2            #+#    #+#             */
/*   Updated: 2022/07/29 04:06:15 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	idx;
	char	*i;

	idx = ft_strlen(s);
	i = (char *)s + (idx - 1);
	if (!c)
		return (++i);
	while (idx)
	{
		if (*i == (char)c)
			return (i);
		idx--;
		i--;
	}
	return (NULL);
}
