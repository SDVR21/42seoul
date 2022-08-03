/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:24:06 by dakim2            #+#    #+#             */
/*   Updated: 2022/07/29 04:15:43 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*re;
	size_t	max;

	max = -1;
	if (size > max / count)
		return (NULL);
	re = malloc(count * size);
	if (!(re))
		return (NULL);
	ft_bzero(re, (count * size));
	return (re);
}
