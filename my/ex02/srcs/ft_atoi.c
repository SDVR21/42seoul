/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 04:36:53 by dakim2            #+#    #+#             */
/*   Updated: 2022/05/04 22:07:48 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int				i;
	int				f;
	unsigned int	re;

	i = 0;
	re = 0;
	f = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{		
		re = re * 10 + (str[i] - '0');
		i++;
	}
	if (i == 0)
		return (-1);
	if (f % 2 == 0)
		return ((int) re);
	else
		return ((int) -re);
}
