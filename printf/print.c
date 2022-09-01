/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:58:41 by dakim2            #+#    #+#             */
/*   Updated: 2022/08/06 18:09:22 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intcom(int f, int a, int b)
{
	if (f)
	{
		if (a > b)
			return (a);
		else
			return (b);
	}
	else
	{
		if (a > b)
			return (b);
		else
			return (a);
	}
}

int	ft_print_pad(int len, char c)
{
	int	res;

	res = 0;
	while (len-- > 0)
		res += ft_putchar(c);
	return (res);
}

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
	int	res;
	int	width;
	int	precision;
	int	putlen;
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

int ft_puti(int d, int padding)
{
	int res;

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
	int		res;
	int		len;
	int		padding;
	int		sign;

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
	return (res + ft_put_base(base10, sign, (unsigned int)d, padding));
}

int	ft_put_u(t_args *args, va_list *ap)
{
	unsigned int	d;
	int		res;
	int		len;
	int		padding;

	res = 0;
        d = va_arg(*ap, unsigned int);
	len = ft_get_digits(d);
	padding = 0;
	if (args->precision && args->precision > len)
		padding = args->precision - len;
	res += ft_print_pad((args->width - (len + padding)), ' ');
	return (res + ft_put_base(base10, 0, d, padding));
}

int	ft_print_hex(int f, unsigned int ud, int padding)
{
	int res;

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
        return (res + ft_print_hex(args->X, (unsigned int)d, padding));
}
//
//static size_t	ft_len(unsigned long long n, char *base)
//{
//	size_t				len;
//	unsigned long long	base_len;
//
//	len = 1;
//	base_len = ft_strlen(base);
//	while (n >= base_len)
//	{
//		n /= base_len;
//		len++;
//	}
//	return (len);
//}

char	*ft_itoa(unsigned long long n, char *base)
{
	char	*str;
	int	len;
	int	blen;
	unsigned long long nb;

	blen = ft_strlen(base);
	nb = n / blen;
	len = 1;
	while (nb > 0)
	{
		nb /= blen;
		len++;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = base[n % blen];
		len--;
		n /= blen;
	}
	return (str);
}

int	ft_put_p(t_args *args, va_list *ap)
{
	unsigned long	add;
	int		res;
	char		*str;
	void		*p;	

	res = 0;
	if (args->t)
		res += ft_putstr("0x");
	p = va_arg(*ap, void *);
	add = (unsigned long)p;
	str = ft_itoa(add, base16);
	res += ft_putstr(str);
	free(str);
	return (res);
}
