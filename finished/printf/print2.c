/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 21:19:39 by dakim2            #+#    #+#             */
/*   Updated: 2022/09/15 22:41:45 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pad(int len, char c)
{
	int	res;

	res = 0;
	while (len-- > 0)
		res += ft_putchar(c);
	return (res);
}

int	ft_print_hex(int f, unsigned int ud, int padding)
{
	int	res;

	res = 0;
	while (padding-- > 0)
		res += ft_putchar('0');
	if (ud / 16)
		res += ft_print_hex(f, ud / 16, padding);
	if ((ud % 16) >= 10)
	{
		if (f)
			res += ft_putchar(((ud % 16) - 10) + 'A');
		else
			res += ft_putchar(((ud % 16) - 10) + 'a');
	}
	else
		res += ft_putchar((ud % 16) + '0');
	return (res);
}

int	ft_put_x(t_args *args, va_list *ap)
{
	int	d;
	int	res;
	int	len;
	int	putlen;
	int	padding;

	d = va_arg(*ap, int);
	len = ft_get_digits_x(d);
	padding = ft_intcom(0, args->precision - len, 0);
	putlen = len + padding;
	res = ft_print_pad(args->width - putlen, ' ');
	return (res + ft_print_hex(args->x, (unsigned int)d, padding));
}

int	ft_put_base(char *base, int sign, long long d, int padding)
{
	int	res;
	int	len;

	res = 0;
	len = ft_strlen(base);
	if (sign)
	{
		res += ft_putchar('-');
		sign = 0;
	}
	while (padding-- > 0)
		res += ft_putchar('0');
	if (d / len)
		res += ft_put_base(base, sign, d / len, padding);
	res += ft_putchar(base[d % len]);
	return (res);
}

int	ft_put_d(t_args *args, va_list *ap)
{
	long long	d;
	int			res;
	int			len;
	int			padding;
	int			sign;

	res = 0;
	d = va_arg(*ap, int);
	len = ft_get_digits(d);
	padding = 0;
	sign = 0;
	if (args->precision && args->precision > len)
		padding = args->precision - len;
	if (d < 0)
	{
		len++;
		sign = 1;
		d *= -1;
	}
	res += ft_print_pad((args->width - (len + padding)), ' ');
	return (res + ft_put_base(BASE10, sign, (unsigned int)d, padding));
}
