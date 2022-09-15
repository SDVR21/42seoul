/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:07:07 by dakim2            #+#    #+#             */
/*   Updated: 2022/09/15 22:28:47 by dakim2           ###   ########.fr       */
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
	int			sign;

	max = 0x7fffffffffffffff;
	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		sign = ft_ternary(*str, '-', -1, 1);
		str++;
	}
	res = 0;
	while (ft_isdigit(*str))
	{
		if (res < max - (*str - '0') / 10)
			res = 10 * res + (*str - '0');
		else
			res = ft_ternary(sign, -1, max + 1, max);
		str++;
	}
	return (res);
}

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

char	*ft_itoa(unsigned long long n, char *base)
{
	char				*str;
	int					len;
	int					blen;
	unsigned long long	nb;

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
