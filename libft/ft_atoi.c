/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:23:34 by dakim2            #+#    #+#             */
/*   Updated: 2022/07/27 02:46:56 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long	re;
	int				i;
	int				sign;

	i = 0;
	sign = 1;
	re = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign *= -1;
	while (ft_isdigit(str[i]))
	{
		re = re * 10 + (str[i] - '0');
		i++;
	}
	if (sign > 0 && re > 2147483647)
		return (-1);
	if (sign < 0 && re > 2147483648)
		return (0);
	return (sign * re);
}
