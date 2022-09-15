/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 22:14:26 by dakim2            #+#    #+#             */
/*   Updated: 2022/08/31 23:03:13 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *buf, char *save)
{
	int	co;
	char	*tmp;

	co = 1;
	while (co)
	{
		co = read(fd, buf, BUFFER_SIZE);
		if (co == -1)
			return (NULL);
		else if (co == 0)
			break ;
		buf[co] = '\0';
		if (!save)
			save = ft_strdup("");
		tmp = save;
		save = ft_strjoin(tmp, buf);
		if (!save)
			return (NULL);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buf, 'n'))
			break ;
	}
	return (save);
}

char	*ft_extract(char *line)
{
	int	i;
	char	*re;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (0);
	re = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!re)
		return (NULL);
	if (line[0] == '\0')
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (re);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = ft_read_line(fd, buf, save);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	save = ft_extract(line);
	return (line);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*rtn;

	i = 0;
	while (s1[i])
		++i;
	rtn = (char *)malloc(sizeof(char) * i + 1);
	if (rtn)
	{
		i = -1;
		while (s1[++i])
			rtn[i] = s1[i];
		rtn[i] = 0;
	}
	return (rtn);
}
