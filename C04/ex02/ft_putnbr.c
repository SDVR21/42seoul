/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 23:44:56 by dakim2            #+#    #+#             */
/*   Updated: 2022/04/19 23:45:09 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	recursive(long long int nb)
{
	char	n;

	n = '0';
	if (nb < 0)
	{
		write(1, "-", 1);
		recursive(-nb);
		return ;
	}
	if (nb >= 10)
	{
		recursive(nb / 10);
	}
	n = nb % 10 + '0';
	write(1, &n, 1);
}

void	ft_putnbr(int nb)
{
	recursive(nb);
}
