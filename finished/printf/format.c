/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:26:57 by dakim2            #+#    #+#             */
/*   Updated: 2022/09/15 22:54:41 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	read_args2(t_args *args, char *itr)
{
	if (ft_isdigit(*itr))
	{
		args->width = ft_atoi(itr);
		itr += ft_get_digits(args->width);
	}
	if (*itr == '.')
	{
		itr++;
		if (ft_isdigit(*itr))
		{
			args->precision = ft_atoi(itr);
			itr += ft_get_digits(args->precision);
		}
	}
}

char	*read_args(t_args *args, char *itr)
{
	if (!itr || *itr != '%')
		return (itr);
	itr++;
	while (*itr)
	{
		initialize_args(args);
		read_args2(args, itr);
		if (ft_strchr(CONV, *itr))
		{
			args->t = *itr;
			if (*itr == 'X')
			{
				args->t = 'x';
				args->x = 1;
			}
			itr++;
			return (itr);
		}
		itr++;
	}
	return (itr);
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

int	ft_get_digits_x(unsigned int ud)
{
	int	digits;

	digits = 0;
	while (ud / 16)
	{
		digits++;
		ud /= 16;
	}
	digits++;
	return (digits);
}

int	ft_ternary(char a, char b, int c, int d)
{
	if (a == b)
		return (c);
	return (d);
}
