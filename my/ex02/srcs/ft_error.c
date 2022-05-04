/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 07:46:49 by dakim2            #+#    #+#             */
/*   Updated: 2022/05/02 07:50:30 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex02.h"

void	error(char *file, char *fn)
{
	ft_putstr(basename(file));
	ft_putstr(": ");
	ft_putstr(fn);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
	errno = 0;
}
