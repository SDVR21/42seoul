/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 19:57:18 by dakim2            #+#    #+#             */
/*   Updated: 2022/04/21 17:00:10 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_puthex(unsigned char c)
{
	unsigned char	re[2];

	re[0] = "0123456789abcdef"[c / 16];
	re[1] = "0123456789abcdef"[c % 16];
	write(1, re, 2);
}

void	ft_print_addr(unsigned long long int ad)
{
	int		i;
	char	addr[16];

	i = 15;
	while (i < 16)
	{
		addr[i--] = "0123456789abcdef"[ad % 16];
		ad /= 16;
	}
	write(1, addr, 16);
}

void	ft_print_hex2(char *str, int size)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		if (i < size)
			ft_puthex((unsigned char) str[i]);
		else
			write(1, "    ", 2);
		if (i % 2 != 0)
			write(1, " ", 1);
		i++;
	}
	while (i < 16)
	{
		write(1, " ", 1);
		i++;
	}
}

void	ft_print_line(char *str, int size)
{
	int						i;
	unsigned long long int	ad;

	ad = (unsigned long long int) str;
	ft_print_addr(ad);
	write(1, ": ", 2);
	ft_print_hex2(str, size);
	i = 0;
	while (i < size)
	{
		if (str[i] >= 32 && str[i] <= 126)
			write(1, str + i, 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	co;

	co = 0;
	while (co < (size / 16))
	{
		ft_print_line(addr + (co * 16), 16);
		co++;
	}
	if (size - (co * 16))
		ft_print_line(addr + (co * 16), size - (co * 16));
	return (addr);
}
