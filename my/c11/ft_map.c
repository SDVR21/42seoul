
#include <stdlib.h>
int *ft_map(int *tab, int length, int(*f)(int))
{
int *re;
int i;
i = 0;
re = (int *)malloc(sizeof(int) * length);
if (!re)
return NULL;
while (i < length)
{
re[i] = (*f)(tab[i]);
i++;
}
return (re);
}
