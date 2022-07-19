/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:25:29 by dakim2            #+#    #+#             */
/*   Updated: 2022/07/17 21:30:41 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	f;
	size_t	i;

	i = 0;
	f = 0;
	if (needle == NULL)
		return (haystack);
	while (haystack[i] && (i < len))
	{
		if (haystack[i] == needle[0])
		{
			f = ft_strncmp((char *)haystack + i, needle, ft_strlen(needle));
			if (!f)
				return (str + i);
		}
		i++;
	}
	return (NULL);
}
