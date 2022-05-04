/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 04:37:35 by dakim2            #+#    #+#             */
/*   Updated: 2022/05/02 07:50:00 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX02_H
# define EX02_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <libgen.h>
# include <string.h>

int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	error(char *file, char *fn);
void	read_one(char *file, char *fn, int size);
void	read_files(char *file, char *fn, int size);
void	file_read(int fd, int size);
int		ft_atoi(char *str);

#endif
