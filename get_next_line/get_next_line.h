/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 22:14:48 by dakim2            #+#    #+#             */
/*   Updated: 2022/09/03 19:13:54 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/*
char    *ft_read_line(int fd, char *buf, char *save)
char    *ft_extract(char *line)
char    *get_next_line(int fd)
char    *ft_strdup(const char *s1)
*/
char	*get_next_line(int fd);
char	*read_line(int fd, char *buf, char *save);
char	*extract(char *line);

char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_substr(char const *s, unsigned int start, size_t len);
size_t  ft_strlen(const char *s);
char    *ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
#endif
