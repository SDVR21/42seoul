/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:24:08 by dakim2            #+#    #+#             */
/*   Updated: 2022/04/28 16:23:50 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ischarset(char c, char *cs)
{
	int	i;

	i = 0;
	while (cs[i])
	{
		if (cs[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_wordcount(char *str, char *charset)
{
	int	co;
	int	i;

	co = 0;
	i = 0;
	while (str[i])
	{
		if (!ft_ischarset(str[i], charset) && ft_ischarset(str[i + 1], charset))
			co++;
		i++;
	}
	return (co + 1);
}

char	*ft_strdup(char *str, int s, int e)
{
	char	*re;
	int		i;

	i = 0;
	re = (char *)malloc(sizeof(char) * (e - s + 1));
	if (!re)
		return (0);
	while (str[i] && s < e)
		re[i++] = str[s++];
	re[i] = '\0';
	return (re);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		i;
	int		j;
	int		s;

	i = 0;
	s = 0;
	j = 0;
	arr = (char **)malloc(sizeof(char *) * (ft_wordcount(str, charset) + 1));
	if (!arr)
		return (0);
	while (str[i])
	{
		while (str[i] && ft_ischarset(str[i], charset))
			i++;
		if (!str[i])
			break ;
		s = i;
		while (str[i] && !ft_ischarset(str[i], charset))
			i++;
		arr[j++] = ft_strdup(str, s, i);
	}
	arr[j] = 0;
	return (arr);
}
