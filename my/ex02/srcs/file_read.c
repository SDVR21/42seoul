/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 05:11:33 by dakim2            #+#    #+#             */
/*   Updated: 2022/05/02 07:48:28 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex02.h"

void	read_one(char *file, char *fn, int size)
{
	int	fd;

	fd = open(fn, O_RDONLY);
	if (fd < 0)
	{
		error(file, fn);
		return ;
	}
	file_read(fd, size);
	close(fd);
}

void	read_files(char *file, char *fn, int size)
{
	int	fd;

	fd = open(fn, O_RDONLY);
	if (fd < 0)
	{
		error(file, fn);
		return ;
	}
	ft_putstr("==> ");
	ft_putstr(fn);
	ft_putstr(" <==\n");
	file_read(fd, size);
	close(fd);
}

void	file_read(int fd, int size)
{
	int		byte;
	char	*buf;
	int		i;

	byte = size + 1;
	i = 0;
	buf = (char *)malloc(sizeof(char) * (size));
	while (byte >= size)
		byte = read(fd, buf, size);
	write(1, buf + byte, size - byte);
	write(1, buf, byte - 1);
	write(1, "\n", 1);
}
