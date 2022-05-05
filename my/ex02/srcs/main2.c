/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 01:45:21 by dakim2            #+#    #+#             */
/*   Updated: 2022/05/05 02:14:49 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex02.h"

void	file_name(char *fn, int i)
{
	if (i == 3)
		return ;
	ft_putstr("==> ");
	ft_putstr(fn);
	ft_putstr(" <==\n");
}

void	file_read(int fd, int size)
{
	int		byte;
	char	*buf;
	int		i;

	byte = size + 1;
	i = 0;
	buf = (char *)malloc(sizeof(char) * (size));
	init(buf, size);
	while (byte >= size)
		byte = read(fd, buf, size);
	write(1, buf + byte, size - byte);
	write(1, buf, byte);
}

void	ft_tail(int fd, int size)
{
	int		i;ddddddd
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

int	check_input(int ac, char **av, int *size)
{
	if (ac < 3)
		return (ac + 1);
	*size = ft_atoi(av[2]);
	if (*size == -1)
		return (-1);
	return (3);
}

int	main(int ac, char **av)
{
	int	i;
	int	size;
	int	fd;

	size = 0;
	i = check_input(ac, av, &size);
	if (i == ac)
		ft_tail(0, size);
	while (i < ac)
	{
		fd = open(av[i], O_RDONLY);
		if (fd < 0)
		{
			error(av[0], av[i]);
			return ;
		}
		file_name(fn, i);
		ft_tail(fd, size);
		close(fd);
		i++;
	}
	return (0);
}
