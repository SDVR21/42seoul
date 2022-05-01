/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:53:24 by dakim2            #+#    #+#             */
/*   Updated: 2022/04/21 16:50:37 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_puthex(unsigned char c)
{
	unsigned char	re[2];

	write(1, "\\", 1);
	re[0] = "0123456789abcdef"[c / 16];
	re[1] = "0123456789abcdef"[c % 16];
	write(1, re, 2);
}

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] <= 31 || str[i] >= 127)
			ft_puthex((unsigned char)str[i]);
		else
			write(1, str + i, 1);
		i++;
	}
}
