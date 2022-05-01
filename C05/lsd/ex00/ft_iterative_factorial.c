/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:15:51 by dakim2            #+#    #+#             */
/*   Updated: 2022/04/25 16:07:42 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	unsigned int	re;

	if (nb < 0)
		return (0);
	re = 1;
	while (nb > 0)
	{
		re *= nb;
		nb--;
	}
	return (re);
}
