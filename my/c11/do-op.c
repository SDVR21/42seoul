
#include <unistd.h>

int main(int ac, char **av)
{
if (ac != 4)
  return (0);
if (av[2][1] != 0)
  return (0);
if (!(av[2][0]=='+' ||av[2][0]=='-'||av[2][0]=='/'||av[2][0]=='*'||av[2][0] =='%'))
{
write(1, "0\n", 2);
return (0);
}
if (av[2][0]=='/' && av[3][0] == '0')
{
write(1, "Stop : division by zero\n", 24);
return (0);
}

if (av[2][0]=='%' && av[3][0] == '0')
{
write(1, "Stop : modulo by zero\n", 22);
return (0);
}
int a = atoi(ac[1]);
int b = atoi(ac[3]);
ft_do_op(a, b, av[2][0]);
write(1, "ok\n", 3);
return (0);
}
