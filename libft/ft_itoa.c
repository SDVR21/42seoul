/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 03:12:54 by dakim2            #+#    #+#             */
/*   Updated: 2022/07/27 02:20:53 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*re;
	size_t	len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = get_len(n);
	re = malloc(sizeof(char) * (len + 1));
	if (re == NULL)
		return (NULL);
	re[len--] = '\0';
	if (n < 0)
	{
		re[0] = '-';
		n = -n;
	}
	if (n == 0)
		re[0] = '0';
	while (n)
	{
		re[len--] = (n % 10) + '0';
		n = n / 10;
	}
	return (re);
}
