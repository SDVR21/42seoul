/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:22:06 by dakim2            #+#    #+#             */
/*   Updated: 2022/04/19 20:06:13 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		j;

	i = ft_strlen(dest);
	j = 0;
	while (j < ft_strlen(src))
	{
		dest[i++] = src[j++];
	}
	dest[i] = '\0';
	return (dest);
}
