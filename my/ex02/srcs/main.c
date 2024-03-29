/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 04:24:31 by dakim2            #+#    #+#             */
/*   Updated: 2022/05/05 01:39:32 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex02.h"

void	init(char *str, int size)
{
	int	i;

	i = 0;
	while (i < size)
		str[i] = 0;
}

void	ft_stdin(int size)
{
	char	*buf;
	int		i;

	i = 0;
	if (size == 0)
	{
		zero_stdin();
		return ;
	}
	buf = (char *)malloc(sizeof(char) * (size));
	init(buf, size);
	while (read(0, buf + i, 1))
		i = (i + 1) % size;
	write(1, buf + i, size - i);
	write(1, buf, i);
}

void	ft_tail(int ac, char **av, int size)
{
	int		i;
	int		f;
	t_fl	*fl;

	i = 3;
	f = 0;
	fl = malloc(sizeof(t_fl));
	fl->f = 0;
	fl->i = 3;
	if (ac == 4)
		read_one(av[0], av[3], size);
	else
	{
		while (i < ac)
		{
			read_files(av[0], av[i], size, fl);
			i++;
			fl->i += 1;
		}
	}
}

int	main(int ac, char **av)
{
	int	size;

	if (ac < 3)
	{
		illegal_offset(av[0], av[2]);
		return (-1);
	}
	size = ft_atoi(av[2]);
	if (size == -1)
		return (-1);
	if (ac == 3)
	{
		ft_stdin(size);
		return (0);
	}
	ft_tail(ac, av, size);
	return (0);
}
