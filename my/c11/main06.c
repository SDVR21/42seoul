#include <stdio.h>
void	ft_sort_string_tab(char **tab);

int main(int ac, char **av)
{
	ft_sort_string_tab(av + 1);
	int i;
	for (i = 1; i <ac; i++)
		printf("%s ", av[i]);
}