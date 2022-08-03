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
	int	i;
	size_t	co;

	if (!s)
		return (0);
	i = 0;
	co = 0;
	while (s[i])
	{
		if (s[i] != c && s[i + 1] == c)
			co++;
		i++;

	}
	return (co);
}

char		**ft_split(char const *s, char c)
{
	char	**re;
	size_t	wd;
//	char	*e;

	wd = ft_wd(s, c);
	re = malloc(sizeof(char *) * (wd + 1));
	if (!re)
		return (NULL);
/*	while (in < wd)
	{
		e = s;
		while (*e != c)
			e++;
		re[in++] = ft_strndup(s, e - s);
		s = e;
		while (*s == c)
			s++;
	}
*/	re[wd] = NULL;
	return (re);
}
