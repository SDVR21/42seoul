/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 02:51:13 by dakim2            #+#    #+#             */
/*   Updated: 2022/04/17 02:59:33 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

extern void		rush(int x, int y);

int	main(int ac, char **av)
{
	if (!ac)
		return 0;
    int x = atoi(av[1]);
    int y = atoi(av[2]);
    printf("\ntest case: x%d y%d\n", x, y);
	rush(x, y);
	return (0);
}
