

int ft_count_if(char **tab, int length, int(*f)(char*))
{
int co;
int i;
co = 0;
i = 0;
while(tab[i])
{
if (f(tab[i]) != 0)
co++;
i++;
}
return (co);
}
