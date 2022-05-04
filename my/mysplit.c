#include <stdlib.h>
#include <stdio.h>
int is_space(char c)
{
	if ((c >= 9 && c <= 13 ) || c == 32)
		return 1;
	return 0;
}

char *my_word(char *str)
{
	char *s;
	s = (char*)malloc(sizeof(char)*5);
	s = "asd";
	return s;
}

char **my_split(char *str)
{
	char **re;
	char *s;
	int i;
	int j;
	int k;
	int flag;
	int l;
	flag = 1;
	i = 0;
	j = 0;
	re = (char **) malloc (sizeof(char*)*10);
	while (str[i])
	{
		if(!is_space(str[i]))
		{
			flag = 1;
		}
		if(flag)
		{
			//l = w_len(str + i);
			re[j] = my_word(str+i);
			printf("re[j]: %s\n", re[j]);
			flag = 0;
			j++;
		}
		i++;
	}
	return re;
}


#include <stdio.h>
int main(int ac, char **av)
{
	char **p;
	p = my_split(av[1]);
	printf("av[1]: %s\n\n", av[1]);
	int i = 0;
	printf("%s, %s, %s\n", p[0], p[1], p[2]);	
	return 0;
}
