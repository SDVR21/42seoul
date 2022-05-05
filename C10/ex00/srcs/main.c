/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 08:02:46 by dakim2            #+#    #+#             */
/*   Updated: 2022/05/02 08:03:31 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	file_read(char *fn);

int	main(int ac, char **av)
{
	int	fd;

	if (ac == 1)
	{
		write(1, "File name missing.\n", 19);
		return (-1);
	}
	if (ac > 2)
	{
		write(1, "Too many arguments.\n", 20);
		return (-1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "Cannot read file.\n", 18);
		return (-1);
	}
	close(fd);
	file_read(av[1]);
	return (0);
}
