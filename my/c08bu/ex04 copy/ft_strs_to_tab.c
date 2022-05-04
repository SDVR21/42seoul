/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 21:55:07 by dakim2            #+#    #+#             */
/*   Updated: 2022/04/26 14:46:17 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*re;
	int		l;

	l = 0;
	while (str[l])
		l++;
	re = (char *)malloc(sizeof(char)*(l + 1));
	if (!re)
		return (0);
	l = 0;
	while (str[l])
	{
		re[l] = str[l];
		l++;
	}
	re[l] = '\0';
	return (re);
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str *re;

	i = 0;
	re = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!re)
		return (0);
	while (i < ac)
	{
		re[i].size = ft_strlen(av[i]);
		re[i].str = av[i];
		re[i].copy = ft_strdup(av[i]);
		i++;
	}
	re[i].str = 0;
	re[i].copy = 0;
	return (re);
}
