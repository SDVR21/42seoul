
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#define CONV "cspdiuxX%"

typedef struct  s_args
{
        int c;
        int width;
        int has_width;
        int precision;
        int has_precision;
}               t_args;

char *ft_strchr(char *str, char c);
int ft_putchar(char c);
int ft_putstr(char *str);
int ft_putstrl(char *str, int len);
int     ft_isspace(char c);
void    initialize_args(t_args *args);
int     ft_atoi(char *str);
int     ft_get_digits(int d);
int     ft_get_digits_x(unsigned int ud);
char    *read_args(t_args *args, char *itr);
int     ft_strlen(char *s);
int     ft_put_s(t_args *args, va_list ap);
int ft_puti(int d, int padding);
int ft_putx(unsigned int ud, int padding);
int ft_put_d(t_args *args, va_list ap);
int ft_put_x(t_args *args, va_list ap);
int ft_put_conv(t_args *args, va_list ap);
int ft_printf(const char * format, ...);
#endif
