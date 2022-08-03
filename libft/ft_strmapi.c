/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:27:17 by dakim2            #+#    #+#             */
/*   Updated: 2022/07/29 06:14:47 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int	i;
	char	*re;

	i = 0;
	re = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!re)
		return (NULL);
	while (s[i])
	{
		re[i] = f(i, s[i]);
		i++;
	}
	re[i] = '\0';
	return (re);
}
