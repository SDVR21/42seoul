/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:14:15 by dakim2            #+#    #+#             */
/*   Updated: 2022/04/16 16:59:04 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_str(int n, char *str)
{
	write(1, str, n);
}

void	dfs(int index, int num, int n, char *m)
{
	if (index == n)
	{
		if (m[0] == ((10 - n) + '0'))
		{
			ft_print_str(n, m);
			return ;
		}
		ft_print_str(n, m);
		write(1, ", ", 2);
		return ;
	}
	else
	{
		while (num <= 9)
		{
			m[index] = num + '0';
			dfs(index + 1, num + 1, n, m);
			num++;
		}
	}
}

void	ft_print_combn(int n)
{
	char	c[9];

	dfs(0, 0, n, c);
}
