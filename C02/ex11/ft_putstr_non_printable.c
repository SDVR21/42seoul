/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:53:24 by dakim2            #+#    #+#             */
/*   Updated: 2022/04/20 23:09:18 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_puthex(int h)
{
	write(1, "\\", 1);
	if (h != 127)
	{
		ft_putchar(h / 16 + '0');
		if (h % 16 < 10)
			ft_putchar((h % 16) + '0');
		else
		{
			if (h < 16)
				ft_putchar('a' + (h - 10));
			else
				ft_putchar('a' + (h - 26));
		}
	}
}



int	ft_strlen(unsigned char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr_non_printable(unsigned char *str)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] <= 31 || str[i] >= 127)
			ft_puthex(str[i]);
		else
			ft_putchar(str[i]);
		i++;
	}
}

#include <stdio.h>
int main()
{
    //ex11
    printf("ex11\n");
    unsigned char ex11_str[] = "Coucou\ntu vas bien ?";
    ex11_str[6] = 244;
	printf("str : %s\n", ex11_str);
	ft_putstr_non_printable(ex11_str);
    printf("\n");
}
