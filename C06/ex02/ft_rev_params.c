/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:24:25 by dakim2            #+#    #+#             */
/*   Updated: 2022/04/21 16:24:04 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	int	l;
	int	i;

	i = ac - 1;
	while (i > 0)
	{
		l = ft_strlen(av[i]);
		write(1, av[i], l);
		write(1, "\n", 1);
		i--;
	}
	return (0);
}
