/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 21:44:08 by dakim2            #+#    #+#             */
/*   Updated: 2022/05/03 11:48:32 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	c_print_addr(int size)
{
	int		i;
	char	addr[8];

	i = 7;
	while (i >= 0)
	{
		addr[i--] = "0123456789abcdef"[size % 16];
		size /= 16;
	}
	write(1, addr, 8);
}

void	c_print_hex2(char *str, int size)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i < size)
			ft_puthex((unsigned char) str[i]);
		else
			write(1, "  ", 2);
		write(1, " ", 1);
		if (i == 7)
			write(1, " ", 1);
		i++;
	}
	while (i < 16)
	{
		write(1, " ", 1);
		i++;
	}
}

void	c_print_line(char *str, int size, int co)
{
	int	i;

	i = 0;
	c_print_addr(co);
	write(1, "  ", 2);
	c_print_hex2(str, size);
	write(1, " |", 2);
	while (i < size)
	{
		if (str[i] >= 32 && str[i] <= 126)
			write(1, str + i, 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "|", 1);
	write(1, "\n", 1);
}

void	*c_print_memory(void *addr, unsigned int size)
{
	unsigned int	co;
	char			buf[16];
	int				flag;

	co = 0;
	flag = 0;
	while (co < (size / 16))
	{
		if (ft_strcmp(addr + (co * 16), buf) == 0)
			flag = 1;
		else
		{
			if (flag)
				write(1, "*\n", 2);
			c_print_line(addr + (co * 16), 16, co * 16);
			flag = 0;
		}
		ft_strcpy(buf, addr + (co * 16));
		co++;
	}
	if (size - (co * 16))
		c_print_line(addr + (co * 16), size - (co * 16), co * 16);
	c_print_addr(size);
	write(1, "\n", 1);
	return (addr);
}
