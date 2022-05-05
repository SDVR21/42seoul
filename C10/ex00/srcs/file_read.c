/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 22:07:44 by dakim2            #+#    #+#             */
/*   Updated: 2022/05/02 08:03:21 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	file_read(char *fn)
{
	int		by;
	char	buf[200];
	int		fd;

	by = 1;
	fd = open(fn, O_RDONLY);
	while (by > 0)
	{
		by = read(fd, buf, 200);
		write(1, &buf, by);
	}
	close(fd);
}
