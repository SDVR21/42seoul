/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:14:30 by dakim2            #+#    #+#             */
/*   Updated: 2022/07/29 03:15:56 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		if (!s1[i] || !s2[i] || (s1[i] != s2[i]))
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
