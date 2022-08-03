/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:07:23 by dakim2            #+#    #+#             */
/*   Updated: 2022/07/31 18:33:14 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tp;
	t_list	*lp;
	t_list	*re;

	lp = lst;
	re = NULL;
	while (lp)
	{
		tp = ft_lstnew(f(lp->content));
		if (tp == NULL)
		{
			ft_lstclear(&tp, del);
			return (NULL);
		}
		ft_lstadd_back(&re, tp);
		lp = lp->next;
	}
	return (re);
}
