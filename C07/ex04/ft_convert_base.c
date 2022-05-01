/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 03:15:06 by dakim2            #+#    #+#             */
/*   Updated: 2022/05/01 15:19:57 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *nbr, char *base);
int	ft_available(char *base);

unsigned int	ft_minus(int nb)
{
	unsigned int	nbr;

	if (nb < 0)
		nbr = -nb;
	else
		nbr = nb;
	return (nbr);
}

char	*ft_itoa_base(int nb, char *base_to, unsigned int l)
{
	char			stack[500];
	int				top;
	char			*re;
	int				i;
	unsigned int	nbr;

	i = 0;
	top = 0;
	nbr = ft_minus(nb);
	while (nbr >= l)
	{
		stack[top++] = base_to[nbr % l];
		nbr /= l;
	}
	if (nbr < l)
		stack[top++] = base_to[nbr % l];
	if (nb < 0)
		stack[top++] = '-';
	re = (char *)malloc(sizeof(char) * (top + 1));
	while (top >= 0)
		re[i++] = stack[--top];
	re[i - 1] = '\0';
	return (re);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int				nb;
	char			*re;
	unsigned int	l;

	nb = 0;
	l = 0;
	if (!ft_available(base_from))
		return (NULL);
	if (!ft_available(base_to))
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	while (base_to[l])
		l++;
	re = ft_itoa_base(nb, base_to, l);
	return (re);
}
