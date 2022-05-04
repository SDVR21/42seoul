/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:22:12 by dakim2            #+#    #+#             */
/*   Updated: 2022/04/16 18:40:46 by yekim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern void		ft_putchar(char c);

char	draw(int x, int y, int i, int j)
{
	char	c;

	if (i == 0 || i == (y - 1))
	{
		if (j == 0 || j == (x - 1))
			c = 'o';
		else
			c = '-';
	}
	else
	{
		if (j == 0 || j == (x - 1))
			c = '|';
		else
			c = ' ';
	}
	return (c);
}

void	rush(int x, int y)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < y)
	{	
		j = 0;
		while (j < x)
		{
			c = draw(x, y, i, j);
			ft_putchar(c);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
