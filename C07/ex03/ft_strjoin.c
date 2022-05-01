/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 01:59:09 by dakim2            #+#    #+#             */
/*   Updated: 2022/05/01 15:21:34 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strsize(int size, char **strs, char *sep)
{
	int	re;
	int	sepl;
	int	i;

	re = 0;
	sepl = ft_strlen(sep);
	i = 0;
	if (size == 1)
		return (ft_strlen(strs[0]) + 1);
	while (i < size - 1)
	{
		re += ft_strlen(strs[i]);
		re += sepl;
		i++;
	}
	re += ft_strlen(strs[i]);
	return (re + 1);
}

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		j;

	i = ft_strlen(dest);
	j = 0;
	while (j < ft_strlen(src))
	{
		dest[i++] = src[j++];
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*re;

	i = 0;
	if (size == 0)
	{
		re = (char *)malloc(1);
		re[0] = 0;
		return (re);
	}
	re = (char *)malloc(sizeof(char) * ft_strsize(size, strs, sep));
	if (!re)
		return (0);
	re[0] = '\0';
	while (i < size - 1)
	{
		re = ft_strcat(re, strs[i]);
		re = ft_strcat(re, sep);
		i++;
	}
	re = ft_strcat(re, strs[i]);
	return (re);
}
