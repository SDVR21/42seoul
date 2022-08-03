/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:29:29 by dakim2            #+#    #+#             */
/*   Updated: 2022/07/28 23:55:38 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d;
	size_t	s;
	size_t	i;

	d = ft_strlen(dst);
	s = ft_strlen(src);
	i = d;
	if (!dstsize)
		return (s);
	if (dstsize <= d)
		return (dstsize + s);
	while (src[i - d] && i + 1 < dstsize)
	{
		dst[i] = src[i - d];
		i++;
	}
	dst[i] = '\0';
	return (d + s);
}
