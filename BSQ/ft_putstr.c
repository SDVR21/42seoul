/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 21:49:20 by dakim2            #+#    #+#             */
/*   Updated: 2022/05/03 00:08:51 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int		len;

	len = ft_strlen(str);
	write(1, str, len);
}

void	ft_puthex(unsigned char c)
{
	unsigned char	re[2];

	re[0] = "0123456789abcdef"[c / 16];
	re[1] = "0123456789abcdef"[c % 16];
	write(1, re, 2);
}
