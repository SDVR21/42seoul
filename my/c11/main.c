 int *ft_map(int *tab, int length, int(*f)(int));

#include <unistd.h>
#include <stdio.h>
int add_f(int nb)
{
	return (nb + 1);
}


int main()
{
	int tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int *s;
	s = ft_map(tab, 10, add_f);
	int i = 0;
	for (i = 0; i < 10; i++)
		printf("%d ", s[i]);
}
