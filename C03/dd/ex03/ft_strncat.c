/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:33:48 by dakim2            #+#    #+#             */
/*   Updated: 2022/04/19 20:11:29 by dakim2           ###   ########.fr       */
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

int	ft_com(int a, int b, int f)
{
	if (f)
	{
		if (a < b)
			return (b);
		else
			return (a);
	}
	else
	{
		if (a < b)
			return (a);
		else
			return (b);
	}
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int		i;
	int		j;
	int		m;

	i = ft_strlen(dest);
	j = 0;
	m = ft_com(nb, ft_strlen(src), 0);
	while (j < m)
	{
		dest[i++] = src[j++];
	}
	dest[i] = '\0';
	return (dest);
}
