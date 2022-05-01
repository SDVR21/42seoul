/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 00:28:07 by dakim2            #+#    #+#             */
/*   Updated: 2022/04/20 21:33:18 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_available(char *base)
{
	int		i;
	int		l;
	int		j;

	i = 0;
	j = 0;
	l = ft_strlen(base);
	if (l <= 1)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (j < l)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			l;
	long int	n;
	char		c;

	n = nbr;
	l = ft_strlen(base);
	if (!ft_available(base))
		return ;
	if (n < 0)
	{
		write(1, "-", 1);
		n = (-n);
	}
	if (n < l)
	{
		c = base[n];
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr_base((n / l), base);
		ft_putnbr_base((n % l), base);
	}
}
