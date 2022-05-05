/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 05:05:16 by dakim2            #+#    #+#             */
/*   Updated: 2022/05/04 22:08:19 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int		len;

	len = ft_strlen(str);
	write(2, str, len);
}

void	zero_stdin(void)
{
	char	buf;
	int		rc;

	rc = 1;
	while (rc > 0)
		rc = read(0, &buf, 1);
}
