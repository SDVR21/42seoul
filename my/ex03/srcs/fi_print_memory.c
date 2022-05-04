/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 21:44:08 by dakim2            #+#    #+#             */
/*   Updated: 2022/05/03 11:45:13 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	fi_print_addr(int size)
{
	int		i;
	char	addr[7];

	i = 6;
	while (i >= 0)
	{
		addr[i--] = "0123456789abcdef"[size % 16];
		size /= 16;
	}
	write(1, addr, 7);
}

void	fi_print_hex2(char *str, int size)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		if (i < size)
			ft_puthex((unsigned char) str[i]);
		else
			write(1, "  ", 2);
		if (i != 15)
			write(1, " ", 1);
		i++;
	}
	while (i < 16)
	{
		write(1, " ", 1);
		i++;
	}
}

void	fi_print_line(char *str, int size, int co)
{
	fi_print_addr(co);
	write(1, " ", 1);
	fi_print_hex2(str, size);
	write(1, "\n", 1);
}

void	*fi_print_memory(void *addr, unsigned int size)
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
			fi_print_line(addr + (co * 16), 16, co * 16);
			flag = 0;
		}
		ft_strcpy(buf, addr + (co * 16));
		co++;
	}
	if (size - (co * 16))
		fi_print_line(addr + (co * 16), size - (co * 16), co * 16);
	fi_print_addr(size);
	write(1, "\n", 1);
	return (addr);
}
