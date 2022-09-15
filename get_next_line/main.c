/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 21:24:43 by dakim2            #+#    #+#             */
/*   Updated: 2022/09/05 23:55:25 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(int ac, char **av)
{
	int fd;
	char *line = NULL;

	if (ac < 2)
	{
		printf("no file name\n");
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	do {
		line = get_next_line(fd);
		printf("%s", line);
	} while (line != 0);
	
	return (0);
}
