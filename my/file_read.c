/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 21:47:20 by dakim2            #+#    #+#             */
/*   Updated: 2022/05/03 12:25:44 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	read_file(char *file, char *fn, char **buf)
{
	int	fd;
	int	fs;

	fd = open(fn, O_RDONLY);
	if (fd < 0)
	{
		error(file, fn);
		return (-1);
	}
	fs = file_size(fd);
	close(fd);
	fd = open(fn, O_RDONLY);
	buf[0] = (char *)malloc(sizeof(char) * fs);
	read(fd, buf[0], fs);
	close(fd);
	return (fs);
}

int	file_size(int fd)
{
	int		by;
	int		size;
	char	buf[200];

	by = 1;
	size = 0;
	while (by > 0)
	{
		by = read(fd, buf, 200);
		size += by;
	}
	return (size);
}
