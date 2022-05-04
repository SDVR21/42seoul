/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 03:06:12 by dakim2            #+#    #+#             */
/*   Updated: 2022/04/24 03:41:37 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	check_input(char *str)
{
	int	i;

	if (ft_strlen(str) != 31)
		return (0);
	i = 0;
	while (str[i])
	{
		if ((str[i] != ' ' && (str[i] < '1' || str[i] > '4')))
			return (0);
		i++;
	}
	return (1);
}

int	*ft_atoi(char *str)
{
	int	*array;
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!(array = (int *)malloc(sizeof(int)*16)))
		return NULL;
	while (i < 32)
	{
		if (str[i] != ' ')
			array[j++] = str[i] - '0';
		i++;		
	}
	return (array);
}
