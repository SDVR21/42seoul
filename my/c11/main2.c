#include <unistd.h>
#include <stdio.h>
int fx(char *a)
{
	if (a[0])
		return (0);
	return 1;
}


int main()
{
//	int tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//	int *s;
	char *tab[] = {"ab", "aa", "ac", "ae", "aee", NULL};
	int s = ft_any(tab, fx);
	int i = 0;
	printf("%d\n", s);
	for (i = 0; i < 5; i++)
		printf("%s ", tab[i]);
}