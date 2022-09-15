/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:27:57 by dakim2            #+#    #+#             */
/*   Updated: 2022/09/15 22:37:05 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_c(t_args *args, va_list *ap)
{
	int	c;
	int	res;
	int	width;

	res = 0;
	width = args->width;
	c = va_arg(*ap, int);
	if (width >= 2)
	{
		width--;
		while (width--)
			res += ft_putchar(' ');
	}
	return (res + ft_putchar(c));
}

int	ft_put_s(t_args *args, va_list *ap)
{
	int		res;
	int		width;
	int		precision;
	int		putlen;
	char	*s;

	width = args->width;
	precision = args->precision;
	s = va_arg(*ap, char *);
	if (!s)
		s = "(null)";
	if (args->precision)
		putlen = ft_intcom(0, precision, ft_strlen(s));
	else
		putlen = ft_strlen(s);
	res = 0;
	while ((width - putlen) > 0)
	{
		res += ft_putchar(' ');
		width--;
	}
	return (res + ft_putstrl(s, putlen));
}

int	ft_put_p(t_args *args, va_list *ap)
{
	unsigned long	add;
	int				res;
	char			*str;
	void			*p;	

	res = 0;
	if (args->t)
		res += ft_putstr("0x");
	p = va_arg(*ap, void *);
	add = (unsigned long)p;
	str = ft_itoa(add, BASE16);
	res += ft_putstr(str);
	free(str);
	return (res);
}

int	ft_put_u(t_args *args, va_list *ap)
{
	unsigned int	d;
	int				res;
	int				len;
	int				padding;

	res = 0;
	d = va_arg(*ap, unsigned int);
	len = ft_get_digits(d);
	padding = 0;
	if (args->precision && args->precision > len)
		padding = args->precision - len;
	res += ft_print_pad((args->width - (len + padding)), ' ');
	return (res + ft_put_base(BASE10, 0, d, padding));
}

int	ft_puti(int d, int padding)
{
	int	res;

	res = 0;
	if (d == -2147483648)
	{
		res += ft_putchar('-');
		while (padding-- > 0)
			res += ft_putchar('0');
		ft_putstr("2147483648");
		return (res);
	}
	if (d < 0)
	{
		res += ft_putchar('-');
		d *= -1;
	}
	while (padding-- > 0)
		res += ft_putchar('0');
	if (d / 10)
		res += ft_puti(d / 10, padding);
	res += ft_putchar((d % 10) + '0');
	return (res);
}
