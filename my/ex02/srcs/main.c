/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 04:24:31 by dakim2            #+#    #+#             */
/*   Updated: 2022/05/02 07:50:56 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex02.h"

void	ft_stdin(int size)
{
	char	*buf;
	int		i;

	i = 0;
	buf = (char *)malloc(sizeof(char) * (size));
	while (read(0, buf + i, 1))
		i = (i + 1) % size;
	write(1, buf + i, size - i);
	write(1, buf, i - 1);
	write(1, "\n", 1);
}

void	ft_tail(int ac, char **av, int size)
{
	int	i;

	i = 3;
	if (ac == 4)
		read_one(av[0], av[3], size);
	else
	{
		while (i < ac)
		{
			read_files(av[0], av[i], size);
			if (i < ac - 1)
				ft_putstr("\n");
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	int	size;

	if (ac < 3)
		return (-1);
	if (av[1][0] != '-' || av[1][1] != 'c')
		return (-1);
	size = ft_atoi(av[2]);
	if (ac == 3)
	{
		ft_stdin(size);
		return (0);
	}
	ft_tail(ac, av, size);
	return (0);
}
