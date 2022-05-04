/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 17:33:15 by dakim2            #+#    #+#             */
/*   Updated: 2022/05/01 18:22:54 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	ft_atoi(char *str)
{
	int				i;
	int				f;
	unsigned int	re;

	i = 0;
	re = 0;
	f = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			f++;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		re = re * 10 + (str[i] - '0');
		i++;
	}
	if (f % 2 == 0)
		return ((int) re);
	else
		return ((int) -re);
}

int	ft_do_op(int a, int b, char c)
{
	int	(*op[5])(int, int);
	int	re;

	re = 0;
	op[0] = &ft_add;
	op[1] = &ft_sub;
	op[2] = &ft_div;
	op[3] = &ft_mul;
	op[4] = &ft_mod;
	if (c == '+')
		re = op[0](a, b);
	else if (c == '-')
		re = op[1](a, b);
	else if (c == '/')
		re = op[2](a, b);
	else if (c == '*')
		re = op[3](a, b);
	else if (c == '%')
		re = op[4](a, b);
	return (re);
}

int	ft_is_op(char c)
{
	if (c == '+' || c == '-' || c == '/')
		return (1);
	if (c == '*' || c == '%')
		return (1);
	return (0);
}

int	ft_error(char **av)
{
	if (!ft_is_op(av[2][0]))
	{
		write(1, "0\n", 2);
		return (0);
	}
	if (av[2][0] == '/' && av[3][0] == '0')
	{
		write(1, "Stop : division by zero\n", 24);
		return (0);
	}
	if (av[2][0] == '%' && av[3][0] == '0')
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	a;
	int	b;
	int	nb;

	if (ac != 4)
		return (0);
	if (!ft_error(av))
		return (0);
	a = ft_atoi(av[1]);
	b = ft_atoi(av[3]);
	nb = ft_do_op(a, b, av[2][0]);
	ft_putnbr(nb);
	write(1, "\n", 1);
	return (0);
}
