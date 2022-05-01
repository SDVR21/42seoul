/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:50:11 by dakim2            #+#    #+#             */
/*   Updated: 2022/04/19 21:06:39 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_num(int n)
{
	char	c[2];

	if (n < 10)
		c[0] = '0';
	else
		c[0] = (n / 10) + '0';
	c[1] = (n % 10) + '0';
	write(1, &c, 2);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			ft_print_num(i);
			write(1, " ", 1);
			ft_print_num(j);
			if (i != 98)
				write(1, ", ", 2);
			j++;
		}
		i++;
	}
}
