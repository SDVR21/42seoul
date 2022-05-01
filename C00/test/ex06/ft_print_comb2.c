/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:50:11 by dakim2            #+#    #+#             */
/*   Updated: 2022/04/16 16:54:27 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_num(char c[])
{
	char	d[2];
	char	tp[2];

	tp[0] = c[0];
	tp[1] = c[1];
	d[0] = c[0];
	d[1] = c[1] + 1;
	while (d[0] <= '9')
	{
		while (d[1] <= '9')
		{
			write(1, &tp, 2);
			write(1, " ", 1);
			write(1, &d, 2);
			if (tp[0] != '9' || tp[1] != '8')
				write(1, ", ", 2);
			d[1]++;
		}
		d[0]++;
		d[1] = '0';
	}
}

void	ft_print_comb2(void)
{
	char	c[2];

	c[0] = '0';
	while (c[0] <= '9')
	{
		c[1] = '0';
		while (c[1] <= '8')
		{
			ft_print_num(c);
			c[1]++;
		}
		c[0]++;
	}
}
