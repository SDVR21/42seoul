/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:25:52 by dakim2            #+#    #+#             */
/*   Updated: 2022/09/15 22:56:06 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define CONV "cspdiuxX%"
# define BASE10 "0123456789"
# define BASE16 "0123456789abcdef"

typedef struct s_args
{
	int	t;
	int	width;
	int	precision;
	int	x;
}				t_args;

/*********** util *************/
char	*ft_strchr(char *str, char c);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putstrl(char *str, int len);
int		ft_strlen(char *s);
int		ft_isspace(char c);
int		ft_atoi(char *str);
int		ft_isdigit(char c);
int		ft_intcom(int f, int a, int b);
char	*ft_itoa(unsigned long long n, char *base);

/*********** format *************/
void	initialize_args(t_args *args);
int		ft_get_digits(long long d);
int		ft_get_digits_x(unsigned int ud);
char	*read_args(t_args *args, char *itr);
int		ft_ternary(char a, char b, int c, int d);

/*********** print *************/
int		ft_put_c(t_args *args, va_list *ap);
int		ft_put_s(t_args *args, va_list *ap);
int		ft_put_p(t_args *args, va_list *ap);
int		ft_put_u(t_args *args, va_list *ap);
int		ft_puti(int d, int padding);
int		ft_print_pad(int len, char c);
int		ft_put_d(t_args *args, va_list *ap);
int		ft_put_x(t_args *args, va_list *ap);
int		ft_print_hex(int f, unsigned int ud, int padding);
int		ft_put_base(char *base, int sign, long long d, int padding);
int		ft_put_conv(t_args *args, va_list *ap);
int		ft_printf(const char *format, ...);
#endif
