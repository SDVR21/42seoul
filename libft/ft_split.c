/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:48:35 by dakim2            #+#    #+#             */
/*   Updated: 2022/07/27 21:49:54 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wd(char const *s, char c)
{
	int		f;
	size_t	co;

	if (!s)
		return (0);
	f = 1;
	co = 0;
	while (*s)
	{
		if (*s == c)
			f = 1;
		else
		{
			if (f)
				co++;
			f = 0;
		}
		s++;
	}
	return (co);
}

static char	*ft_strndup(const char *s1, size_t len)
{
	size_t	i;
	char	*s2;

	i = -1;
	if (len == 0)
		return (NULL);
	s2 = malloc(sizeof(char) * (len + 1));
	if (s2 == NULL)
		return (NULL);
	while (++i < len)
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
}

char	**ft_split(char const *s, char c)
{
	char	**re;
	size_t	wd;
	size_t	in;
	int		i;
	int		j;

	in = 0;
	wd = ft_wd(s, c);
	re = malloc(sizeof(char *) * (wd + 1));
	if (!re)
		return (NULL);
	i = 0;
	while (in < wd && s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[j] != c && s[j])
			j++;
		re[in++] = ft_strndup(&s[i], j - i);
		i = j;
	}
	re[wd] = NULL;
	return (re);
}
