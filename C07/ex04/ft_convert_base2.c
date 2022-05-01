/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 03:14:21 by dakim2            #+#    #+#             */
/*   Updated: 2022/05/01 13:33:41 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_skip(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
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
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == 32)
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

int	ft_basecheck(char c, char *base)
{
	int		i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	long	f;
	long	re;
	int		l;

	i = 0;
	f = 1;
	re = 0;
	l = ft_strlen(base);
	if (!ft_available(base))
		return (0);
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i++] == '-')
			f *= (-1);
	}
	while (str[i] && ft_skip(str[i], base))
	{
		if (ft_basecheck(str[i], base) >= 0)
			re = re * l + ft_basecheck(str[i], base);
		i++;
	}
	return ((int) f * re);
}
