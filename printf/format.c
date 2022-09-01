/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:06:10 by dakim2            #+#    #+#             */
/*   Updated: 2022/08/06 03:07:48 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_args(t_args *args)
{
	args->t = 0;
	args->width = 0;
	args->precision = 0;
	args->X = 0;
}

char	*read_args(t_args *args, char *itr)
{
	if (!itr || *itr != '%')
		return (itr);
	itr++;
	while (*itr)
	{
		initialize_args(args);
		//width
		if (ft_isdigit(*itr))
		{
			args->width = ft_atoi(itr);
			itr += ft_get_digits(args->width);
		}
		//.
		if (*itr == '.')
		{
			itr++;
			if (ft_isdigit(*itr))
			{
				args->precision = ft_atoi(itr);
				itr += ft_get_digits(args->precision);
			}
		}
		//dxxs
		if (ft_strchr(CONV, *itr))
		{
			args->t = *itr;
			if (*itr == 'X')
			{
				args->t = 'x';
				args->X = 1;
			}
			itr++;
			return (itr);
		}
		itr++;
	}
	return (itr);
}
