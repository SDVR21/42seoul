/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 19:57:18 by dakim2            #+#    #+#             */
/*   Updated: 2022/04/23 17:53:23 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_hex(char c)
{
	char	p;

	if (c % 16 < 10)
		p = c % 16 + '0';
	else
		p = c % 16 - 10 + 'a';
	write(1, &p, 1);
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

void	ft_print_hex2(unsigned char *str, int size)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		if (i < size)
		{
			ft_print_hex(str[i] / 16);
			ft_print_hex(str[i] % 16);
		}
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

void	ft_print_line(unsigned char *str, int size)
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



#include <stdio.h>
int	main()
{
	char	str[92] = "Bonjour les aminches   c  est fou tout ce qu on peut faire avec   print_memory    lol lol";
	str[20] = 0x09;
 	str[21] = 0x0a;
 	str[22] = 0x09;
 	str[33] = 0x09;
 	str[38] = 0x09;
 	str[63] = 0x09;
 	str[64] = 0x0a;
 	str[65] = 0x09;
 	str[78] = 0x0a;
 	str[79] = 0x0a;
 	str[80] = 0x0a;
 	str[81] = 0x09;
	str[85] = 0x2e;
	str[89] = 0x0a;
	str[90] = 0x20;
	ft_print_memory(str, 390);
}
