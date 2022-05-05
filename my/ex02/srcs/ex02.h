/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 21:58:54 by dakim2            #+#    #+#             */
/*   Updated: 2022/05/05 01:10:23 by dakim2           ###   ########.fr       */
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

typedef struct s_fl{
	int	f;
	int	i;
}t_fl;

void	init(char *str, int size);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	error(char *file, char *fn);
void	read_one(char *file, char *fn, int size);
void	read_files(char *file, char *fn, int size, t_fl *f);
void	file_read(int fd, int size);
int		ft_atoi(char *str);
void	help_msg(char *file);
void	require_arg(char *file);
void	illegal_option(char *file, char *op);
void	illegal_offset(char *file, char *op);

void	zero_stdin(void);
void	ft_file(int ac, char **av);

#endif
