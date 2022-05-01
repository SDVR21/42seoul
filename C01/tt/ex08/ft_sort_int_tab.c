/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 22:34:29 by dakim2            #+#    #+#             */
/*   Updated: 2022/04/17 00:40:30 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int		tp;

	tp = *a;
	*a = *b;
	*b = tp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int		i;
	int		j;	

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (tab[j] > tab[j + 1])
			{
				ft_swap(tab + j, tab + (j + 1));
			}
			j++;
		}
		i++;
	}
}
