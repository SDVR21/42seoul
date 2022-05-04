/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:51:26 by dakim2            #+#    #+#             */
/*   Updated: 2022/04/17 03:14:54 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern	void	ft_putchar(char c);

void	ft_print_line(char x, char y, char z, int c)
{
	int		i;

	i = 0;
	while (i < c)
	{
		if (i == 0)
			ft_putchar(x);
		else if (i == (c - 1))
			ft_putchar(z);
		else
			ft_putchar(y);
		i++;
	}
	ft_putchar('\n');
	return ;
}

void	rush(int x, int y)
{
	int		i;

	if (x <= 0 || y <= 0)
		return ;
	i = 0;
	while (i < y)
	{
		if (i == 0)
			ft_print_line('A', 'B', 'C', x);
		else if (i == (y - 1))
			ft_print_line('A', 'B', 'C', x);
		else
			ft_print_line('B', ' ', 'B', x);
		i++;
	}
}
