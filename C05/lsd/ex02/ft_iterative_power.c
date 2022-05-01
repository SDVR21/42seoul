/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:21:16 by dakim2            #+#    #+#             */
/*   Updated: 2022/04/25 17:35:02 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	re;

	re = 1;
	if (power == 0)
		return (1);
	if (nb == 0)
		return (0);
	if (power < 0)
		return (0);
	while (power >= 1)
	{
		re *= nb;
		power--;
	}
	return (re);
}
