/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 16:30:50 by dakim2            #+#    #+#             */
/*   Updated: 2022/05/02 00:10:34 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(char **a, int i1, int i2)
{
	char	*tp;

	tp = a[i1];
	a[i1] = a[i2];
	a[i2] = tp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	int		len;

	i = 0;
	len = 0;
	while (tab[len] != NULL)
		len++;
	if (len == 0)
		return ;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - 1 - i)
		{
			if (cmp(tab[j], tab[j + 1]) > 0)
				ft_swap(tab, j, j + 1);
			j++;
		}
		i++;
	}
}
