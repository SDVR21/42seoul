/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 22:50:13 by dakim2            #+#    #+#             */
/*   Updated: 2022/05/01 18:16:23 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sort(int *tab, int length, int flag, int (*f)(int, int))
{
	int	i;

	i = 0;
	if (flag)
	{
		while (i + 1 < length)
		{
			if (f(tab[i], tab[i + 1]) > 0)
				return (0);
			i++;
		}
	}
	else
	{
		while (i + 1 < length)
		{
			if (f(tab[i], tab[i + 1]) < 0)
				return (0);
			i++;
		}
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (i + 1 < length)
	{
		if (f(tab[i], tab[i + 1]) < 0)
		{
			flag = 1;
			break ;
		}
		else if (f(tab[i], tab[i + 1]) > 0)
		{
			flag = 0;
			break ;
		}
		i++;
	}
	return (ft_sort(tab, length, flag, f));
}
