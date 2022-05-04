/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 14:29:41 by dakim2            #+#    #+#             */
/*   Updated: 2022/05/02 00:04:40 by dakim2           ###   ########.fr       */
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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] || s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_string_tab(char **tab)
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
			if (ft_strcmp(tab[j], tab[j + 1]) > 0)
				ft_swap(tab, j, j + 1);
			j++;
		}
		i++;
	}
}
