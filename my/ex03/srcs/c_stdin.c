/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_stdin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:53:22 by dakim2            #+#    #+#             */
/*   Updated: 2022/05/03 11:49:45 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	c_print_stdin(char buf[16], char cmp[16], int *fl, int i)
{
	if (ft_strcmp(buf, cmp) == 0)
	{
		if (*fl != 1)
		{
			write(1, "*\n", 2);
			*fl = 1;
		}
		ft_strcpy(cmp, buf);
		return ;
	}
	else
		*fl = 0;
	c_print_line(buf, 16, i);
	ft_strcpy(cmp, buf);
}

int	c_stdin2(char buf[16], char cmp[16], int *i, int *f)
{
	int				len;
	unsigned char	inp;
	int				j;

	len = 0;
	j = 0;
	while (read(0, &inp, 1))
	{
		if (len < 16)
		{
			buf[j % 16] = inp;
			len++;
		}
		else if (len == 16)
		{
			c_print_stdin(buf, cmp, f, j);
			buf[0] = inp;
			len = 1;
		}
		j++;
	}
	i[0] = j;
	return (len);
}

void	c_stdin(char buf[16], char cmp[16])
{
	int	i;
	int	len;
	int	f;

	i = 0;
	f = 0;
	len = c_stdin2(buf, cmp, &i, &f);
	if (len != 0)
		c_print_line(buf, i % 16, i - len);
	c_print_addr(i);
	write(1, "\n", 1);
}
