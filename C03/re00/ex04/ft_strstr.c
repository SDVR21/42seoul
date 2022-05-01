/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:20:43 by dakim2            #+#    #+#             */
/*   Updated: 2022/04/19 20:16:46 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2, int l)
{
	int		i;

	i = 0;
	while (i < l)
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	len;
	int	f;
	int	i;

	i = 0;
	f = 0;
	if (to_find[i] == '\0')
		return (str);
	len = ft_strlen(to_find);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			f = ft_strcmp(str + i, to_find, len);
			if (!f)
				return (str + i);
		}
		i++;
	}
	return (0);
}
