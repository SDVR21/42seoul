#include <unistd.h>
#include <stdio.h>

int ass(int a, int b)
{
	return (a - b);
}

int ft_is_sort(int *tab, int length, int(*f)(int, int));

int main()
{
	int i;
//	int tab[] = {1, 2, 3, 4, 23, 6, 7, 8, 9, 10};
	int tab[] = {5, 3, 2, 1, 0, -3};
//	int *s;
//	char *tab[] = {"ab", "aa", "ac", "ae", "aee", NULL};
	int s = ft_is_sort(tab, 6, ass);
	printf("%d\n", s);
	for (i = 0; i < 5; i++)
		printf("%d ", tab[i]);
}