/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 19:09:56 by dakim2            #+#    #+#             */
/*   Updated: 2022/08/06 04:54:55 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_atoi(char *str)
{
	long long	res;
	long long	max;
	int		sign;

	max = 0x7fffffffffffffff;
	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		sign = (*str == '-') ? -1 : 1;
		str++;
	}
	res = 0;
	while (ft_isdigit(*str))
	{
		if (res < max - (*str - '0') / 10)
			res = 10 * res + (*str - '0');
		else
			res = (sign == -1) ? (max + 1) : max;
		str++;
	}
	return (res);
}

int	ft_get_digits(long long d)
{
	int	digits;

	if (d == -2147483648)
		return (11);
	digits = 0;
	if (d < 0)
	{
		d *= -1;
	}
	while (d / 10)
	{
		digits++;
		d /= 10;
	}
	digits++;
	return (digits);
}

int     ft_get_digits_x(unsigned int ud)
{
        int digits;

        digits = 0;
        while (ud / 16)
	{
		digits++;
		ud /= 16;
	}
        digits++;
        return (digits);
}
