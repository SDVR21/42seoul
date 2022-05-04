/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:01:35 by dakim2            #+#    #+#             */
/*   Updated: 2022/04/26 14:43:07 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

typedef enum t_bool {
	true = 1,
	false = 0
} t_bool;

# define TRUE true
# define FALSE false
# define EVEN(nb) !(nb % 2)
# define EVEN_MSG "I have an even number of arguments." 
# define ODD_MSG "I have an odd number of arguments."
# define SUCCESS 0

#endif
