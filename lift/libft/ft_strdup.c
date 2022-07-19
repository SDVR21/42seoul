/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:24:43 by dakim2            #+#    #+#             */
/*   Updated: 2022/07/19 17:13:07 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*s2;

	i = -1;
	len = ft_strlen(s1);
	s2 = malloc(sizeof(char) * len);
	if (s2 == NULL)
		return (NULL);
	while (i++ < len)
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
}
