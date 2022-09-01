/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 04:27:23 by dakim2            #+#    #+#             */
/*   Updated: 2022/08/06 16:46:17 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_conv(t_args *args, va_list *ap)
{
	if (args->t == 'c')
		return (ft_put_c(args, ap));
	else if (args->t == 's')
		return (ft_put_s(args, ap));
	else if (args->t == 'p')
		return (ft_put_p(args, ap));
	else if (args->t == 'd')
		return (ft_put_d(args, ap));
	else if (args->t == 'i')
		return (ft_put_d(args, ap));
	else if (args->t == 'u')
		return (ft_put_u(args, ap));
	else if (args->t == 'x')
		return (ft_put_x(args, ap));
	else if (args->t == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char * format, ...)
{
	char	*itr;
	int	res;
	t_args	args;
	va_list	ap;

	itr = (char *)format;
	if (!itr)
		return (0);
	res = 0;
	va_start(ap, format);
	while (*itr)
	{
		if (*itr == '%')
		{
			itr = read_args(&args, itr);
			res += ft_put_conv(&args, &ap);
		//	continue;
		}
		else
		{
			res += ft_putchar(*itr);
			itr++;
		}
	}
	va_end(ap);
	return (res);
}



/**
int ft_printf(const char* format, ...)
{
	va_list ap; // 가변인자 포인터 선언
	len // 총 출력 길이 저장할 변수 선언

	
	while(* format[i] 가 '\0'만날때까지  *)
	{
		// 구조체 초기화
		if (* format[i] 가 '%' 만났다면 *)
		{
			while (* format[i] 가 type 만날때까지 *)
				// 구조체에 각 플래그 할당!
			if (* 현재 인덱스에서 format[i] 가 type인가??  *)
				// 출력모듈로 이동
		}
		else * format[i] 가 '%' 안만났다면 
		{
			// 그냥 char 출력 && 출력 길이 + 1
		}
		
	}


	return (* 총 출력 길이 *);
}
*/
