/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 22:17:37 by dakim2            #+#    #+#             */
/*   Updated: 2022/05/03 11:50:48 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	init(char buf[16], char cmp[16])
{
	int	i;

	i = 0;
	while (i < 16)
	{
		buf[i] = -1;
		cmp[i] = -2;
		i++;
	}
}

int	check_input(int ac, char **av)
{
	char	buf[16];
	char	cmp[16];

	init(buf, cmp);
	if (ac == 1)
	{
		fi_stdin(buf, cmp);
		return (1);
	}
	if (ac == 2 && av[1][0] == '-' && av[1][1] == 'C')
	{
		c_stdin(buf, cmp);
		return (1);
	}
	if (av[1][0] == '-' && av[1][1] == 'C')
		return (3);
	else
		return (2);
}

void	ft_hexdump(char *file, char *fn, int f)
{
	char	*str;
	int		fs;

	fs = read_file(file, fn, &str);
	if (f == 2)
		fi_print_memory(str, fs);
	else
		c_print_memory(str, fs);
	free(str);
}

int	main(int ac, char **av)
{
	int		flag;
	int		i;

	flag = -1;
	flag = check_input(ac, av);
	if (flag == 1)
		return (0);
	if (flag == 2)
	{
		i = 1;
		while (i < ac)
			ft_hexdump(av[0], av[i++], 2);
	}
	else if (flag == 3)
	{
		i = 2;
		while (i < ac)
			ft_hexdump(av[0], av[i++], 3);
	}
	return (0);
}
