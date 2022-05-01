/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:25:52 by dakim2            #+#    #+#             */
/*   Updated: 2022/04/19 20:40:49 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	ld;
	unsigned int	ls;

	i = 0;
	ld = ft_strlen(dest);
	ls = ft_strlen(src);
	if (size <= ld)
		return (ls + size);
	while (src[i] && (ld + i) < (size - 1))
	{
		dest[ld + i] = src[i];
		i++;
	}
	dest[ld + i] = '\0';
	return (ls + ld);
}
