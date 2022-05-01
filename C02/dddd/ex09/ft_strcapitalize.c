/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 04:00:03 by dakim2            #+#    #+#             */
/*   Updated: 2022/04/18 23:00:39 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_char(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		f;

	i = 0;
	f = 1;
	while (str[i] != '\0')
	{
		if (!ft_is_char(str[i]))
			f = 1;
		else
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] = str[i] + 32;
			if (f)
			{
				if (str[i] >= 'a' && str[i] <= 'z')
					str[i] = str[i] - 32;
				f = 0;
			}
		}
		i++;
	}
	return (str);
}
