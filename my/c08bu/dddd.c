#include "ft_stock_str.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	l;

	l = ft_strlen(str);
	write(1, str, l);
}

void	ft_putnbr(int nbr)
{
	char c;

	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	c = nbr % 10 + '0';
	write(1, &c, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	l;
	int	i;

	i = 0;
	l = 0;
	while (par[l].str != 0)
		l++;
	while (i < l)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}
