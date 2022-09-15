/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:24:17 by dakim2            #+#    #+#             */
/*   Updated: 2022/09/15 22:46:40 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_args(t_args *args)
{
	args->t = 0;
	args->width = 0;
	args->precision = 0;
	args->x = 0;
}

int	ft_put_conv(t_args *args, va_list *ap)
{
	if (args->t == 'c')
		return (ft_put_c(args, ap));
	else if (args->t == 's')
		return (ft_put_s(args, ap));
	else if (args->t == 'p')
		return (ft_put_p(args, ap));
	else if (args->t == 'd')
		return (ft_put_d(args, ap));
	else if (args->t == 'i')
		return (ft_put_d(args, ap));
	else if (args->t == 'u')
		return (ft_put_u(args, ap));
	else if (args->t == 'x')
		return (ft_put_x(args, ap));
	else if (args->t == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	char	*itr;
	int		res;
	t_args	args;
	va_list	ap;

	itr = (char *)format;
	if (!itr)
		return (0);
	res = 0;
	va_start(ap, format);
	while (*itr)
	{
		if (*itr == '%')
		{
			itr = read_args(&args, itr);
			res += ft_put_conv(&args, &ap);
		}
		else
		{
			res += ft_putchar(*itr);
			itr++;
		}
	}
	va_end(ap);
	return (res);
}
