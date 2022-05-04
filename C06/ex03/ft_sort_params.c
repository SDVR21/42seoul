/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:43:38 by dakim2            #+#    #+#             */
/*   Updated: 2022/04/25 19:58:49 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(char **a, int i1, int i2)
{
	char	*tp;

	tp = a[i1];
	a[i1] = a[i2];
	a[i2] = tp;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] || s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_print(char **av, int in)
{
	int		i;
	int		l;

	i = 1;
	while (i < in)
	{
		l = ft_strlen(av[i]);
		write(1, av[i], l);
		write(1, "\n", 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	int		i;
	int		j;
	int		in;

	i = 0;
	in = ac;
	if (ac <= 1)
		return (0);
	while (i < in - 1)
	{
		j = 1;
		while (j < in - 1 - i)
		{
			if (ft_strcmp(av[j], av[j + 1]) > 0)
				ft_swap(av, j, j + 1);
			j++;
		}
		i++;
	}
	ft_print(av, in);
	return (0);
}
