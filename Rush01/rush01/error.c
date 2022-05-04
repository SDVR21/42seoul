/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 03:06:12 by dakim2            #+#    #+#             */
/*   Updated: 2022/04/24 22:22:18 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	check_input(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((!is_space(str[i]) && (str[i] < '1' || str[i] > '9')))
			return (0);
		if ((str[i] >= '1' && str[i] <= '9')
			&& (str[i + 1] >= '1' && str[i + 1] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	*ft_atoi(char *str)
{
	int	i;
	int	j;
	int	n;
	int	*array;

	i = 0;
	j = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '9')
			n++;
		i++;
	}
	array = (int *)malloc(sizeof(int) * n);
	i = 0;
	while (str[i])
	{
		if (!is_space(str[i]))
			array[j++] = str[i] - '0';
		i++;
	}
	return (array);
}
