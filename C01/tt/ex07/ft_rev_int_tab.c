/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 22:19:30 by dakim2            #+#    #+#             */
/*   Updated: 2022/04/17 00:38:00 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int		tp;

	tp = *a;
	*a = *b;
	*b = tp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int		i;

	i = 0;
	while (i < (size / 2))
	{
		ft_swap(tab + i, tab + (size - i - 1));
		i++;
	}
}
