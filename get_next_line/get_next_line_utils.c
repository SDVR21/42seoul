/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 22:14:38 by dakim2            #+#    #+#             */
/*   Updated: 2022/08/30 22:43:13 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == 0)
			return (0);
		++s;
	}
	return ((char *)s);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	slen;
	size_t	dlen;

	slen = 0;
	while (src[slen])
		++slen;
	dlen = 0;
	while (dst[dlen] && dlen < dstsize)
		++dlen;
	if (dstsize <= dlen)
		return (dstsize + slen);
	i = 0;
	while (dlen + i + 1 < dstsize && src[i])
	{
		dst[dlen + i] = src[i];
		++i;
	}
	dst[dlen + i] = 0;
	return (dlen + slen);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	dlen;
	char	*dst;

	if (s1 == 0 || s2 == 0)
		return (0);
	dlen = ft_strlen(s1) + ft_strlen(s2);
	dst = (char *)calloc(dlen + 1, sizeof(char));
	if (dst)
	{
		ft_strlcat(dst, s1, dlen + 1);
		ft_strlcat(dst, s2, dlen + 1);
	}
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*dst;

	if (s == 0)
		return (0);
	slen = ft_strlen(s);
	if (slen <= start)
		len = 0;
	slen -= start;
	if (slen < len)
		len = slen;
	dst = (char *)calloc(len + 1, sizeof(char));
	if (dst)
	{
		i = -1;
		while (++i < len && s[start + i])
			dst[i] = s[start + i];
	}
	return (dst);
}
