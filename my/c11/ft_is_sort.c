
int ft_is_sort(int *tab, int length, int(*f)(int, int))
{
int i;
int flag;
i = 0;
flag=0;
while (i + 1< length)
{
if (f(tab[i], tab[i+1]) < 0) //앞에게 더 작음 as
 flag = 1; break;
else if(f(tab[i], tab[i+1]) > 0) //뒤가 더 작음 -> des
	flag = 0; break;
i++;
}

i = 0;
if (f)
{
while (i + 1< length)
{
if(f(tab[i], tab[i+1]) > 0) //뒤가 더 작음 -> des
        return (0);
i++;
}
else{
while (i + 1< length)
{
if(f(tab[i], tab[i+1]) < 0) //뒤가 더 작음 -> des
        return (0);
i++;
}
return (1);

}
return (1);
}
