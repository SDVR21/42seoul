/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 14:06:47 by dakim2            #+#    #+#             */
/*   Updated: 2022/05/01 20:20:06 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_input(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 2)
		return (-1);
	if (av[1][0] == '\0')
		return (-1);
	while (av[1][i])
	{
		if (!(av[1][i] >= '0' && av[1][i] <= '9'))
			return (-1);
		i++;
	}
	// 0으로 시작하면 패싱
	return (i);
}

#include <stdio.h>
int	main(int ac, char **av)
{
	int	co;
	char *str;

	co = check_input(ac, av);
	printf("%d\n", co);
//	if (co == -1)
//		ft_error();
//	str = (char *)malloc(sizeof(char) * 4);
//	if (!str)
//		ft_error();
	print_word(co, av, str);
	return (0);
}
