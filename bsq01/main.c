/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim2 <dakim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:01:46 by dakim2            #+#    #+#             */
/*   Updated: 2022/05/05 01:56:19 by dakim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"


int	**init_map(int fd, t_map *map);
int	init_row(char buf[200], t_map *map);
void init_char(char buf[200], int i, t_map *map);
void	file_to_map(int fd, t_map *map);
t_map *init_t_map(char *fn);
void	map_print(t_map *map);
int file_read(char *fn);


int	**init_map(int fd, t_map *map)
{
	int		**tab;
	int		i;
	int		j;
	char	inp;
	int		*mrow;

	i = 0;
	j = 0;
	tab = (int **)malloc(sizeof(int *) * map->row);
	while (inp != '\n')
		read(fd, &inp, 1);
	while (i < map->row)
	{
		*(tab + i) = (int *)malloc(sizeof(int) * map->col);
		j = 0;
		while (j < map->col)
		{
			read(fd, &inp, 1);
			if (inp == map->emp)
				tab[i][j] = 1;
			else if (inp == map->op)
				tab[i][j] = 0;
			else
				return (NULL);
			j++;
		}
		read(fd, &inp, 1);
		i++;
	}
	return (tab);
}

int	init_row(char buf[200], t_map *map)
{
	int		i;
	char	nbr[200];

	i = 0;
	while (buf[i] <= '9' && buf[i] >= '0')
	{
		nbr[i] = buf[i];
		i++;
	}
	nbr[i] = 0;
	map->row = ft_atoi(nbr);
	return (i);
}

void init_char(char buf[200], int i, t_map *map)
{
	map->emp = buf[i++];
	map->op = buf[i++];
	map->full = buf[i++];
}

void	file_to_map(int fd, t_map *map)
{
	char	inp;
	char	buf[200];
	int		i;
	int		j;

	j = 0;
	while (inp != '\n')
	{
		read(fd, &inp, 1);
		buf[j] = inp;
		j++;
	}
	buf[j] = 0;
	i = init_row(buf, map);
	init_char(buf, i, map);
	j = 0;
	inp = 0;
	while (inp != '\n')
	{
		read(fd, &inp, 1);
		j++;
	}
	map->col = j - 1;
}

t_map *init_t_map(char *fn)
{
	int		fd;
	t_map	*map;
	int		j;

	j = 0;
	fd = file_read(fn);
	map = (t_map *)malloc(sizeof(t_map));
	file_to_map(fd, map);
	close(fd);
	fd = file_read(fn);
	map->tab = init_map(fd, map);
	close(fd);
	return (map);
}

void	map_print(t_map *map)
{
	int i = 0;
	int j = 0;
	printf("row: %d\n", map->row);
	printf("col: %d\n", map->col);
	printf("emp: %c	 op: %c  full: %c\n", map->emp, map->op, map->full);
	while (i < map->row)
	{
		j = 0;
		while (j < map->col) {
			printf("%d", map->tab[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int file_read(char *fn)
{
	int	fd;

	fd = open(fn, O_RDONLY);
	if (fd < 0)
	{
		error();
		exit(1);
	}
	return (fd);
}

void	print_sq(t_max_square *sq)
{
	printf("x: %d y: %d size: %d\n", sq->right_down_x, sq->right_down_y, sq->size);
}

int main(int ac, char **av)
{

	int	i;
	t_map *map;
	t_max_square *sq;
	t_map *new_map;
	
	if (ac == 1)
	{
		map = init_t_map("");
		new_map = init_t_map(av[i]);
		sq = get_largest_square(map);
		print_sq(sq);
		ft_print_solution(sq, new_map);
		return (0);
	}		
	i = 1;
	while (i < ac)
	{
		map = init_t_map(av[i]);
		new_map = init_t_map(av[i]);
		sq = get_largest_square(map);
		print_sq(sq);
		ft_print_solution(sq, new_map);
		i++;
	}
	return (0);
}
