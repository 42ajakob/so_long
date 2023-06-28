/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:52:51 by ajakob            #+#    #+#             */
/*   Updated: 2023/06/28 02:09:13 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	valid_name(const char *argv, const char *ber, int len) 
{
	size_t			i;
	size_t		j;

	i = ft_strlen(argv) - 1;
	j = ft_strlen(ber) - 1;
	if (!argv || i < 4)
		return (0);
	while (len != 0 && argv[i] && ber[j])
	{
		if ((argv[i] != ber[j]))
			return (0);
		i--;
		j--;
		len--;
	}
	return (1);
}

static int	map_size(const char *argv)
{
	char *line;
	int fd;
	int i;
	int y;

	fd = open(argv, O_RDONLY);
	line = malloc(sizeof(char) * 101);
	line[101] = '\0';
	y = 1;
	while (read(fd, line, 100))
	{
		i = 0;
		while (line[i])
		{
			if (line[i] == '\n')
				y++;
			i++;
		}
	}
	free(line);
	if (y > 2)
		return (y);
	return (0);
}

static int	f_l_line(char **map, int y) 
{
	int		x;

	x = 0;
	while (map[0][x])
	{
		if (map[0][x] != '1' && map[0][x] != '\n')
			return (0);
		x++;
	}
	x = 0;
	while (map[y - 1][x])
	{
		if (map[y - 1][x] != '1' && map[y - 1][x] != '\n')
			return (0);
		x++;
	}
	return (1);
}

static int	mid_line(char **map, int last_y)
{
	int		x;
	int 	y;

	x = 0;
	y = 1;
	while (map[y] != map[last_y - 1])
	{
		if (!(map[y][ft_strlen(map[y]) - 1] == '\n' && map[y][ft_strlen(map[y]) - 2] == '1' && map[y][0] == '1'))
			return (0);
		while (map[y][x])
		{
			if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != 'C' && map[y][x] != 'E' && map[y][x] != 'P' && map[y][x] != '\n')
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

static int	PEC(char **map, int *C)
{
	int P;
	int E;
	int x;
	int y;

	P = 0;
	E = 0;
	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				P++;
			if (map[y][x] == 'E')
				E++;
			if (map[y][x] == 'C')
				*C += 1;
			x++;
		}
		x = 0;
		y++;
	}
	if (P == 1 && E == 1 && C > 0)
		return (1);
	return (0);
}

static void	free_ptr(char **ptr)
{
	int i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

static int	FFL(char **map, char *argv, int C)
{
	char **grid;
	int Exit;
	int Coll;
	int x;
	int y;

	Exit = 0;
	Coll = 0;
	x = 0;
	y = 0;
	grid = malloc(sizeof(char *) * (map_size(argv) + 1));
	while (map[y])
	{
		grid[y] = ft_strdup(map[y]);
		y++;
	}
	grid[y] = NULL;
	y = 0;
	while (!(ft_strchr(grid[y], 'P')))
		y++;
	while (grid[y][x] != 'P')
		x++;
	DFS(&*grid, x, y, &Exit, &Coll);
	free_ptr(grid);
	if (Exit == 1 && Coll == C)
		return (1);
	return (0);
}

int	DFS(char **grid, int x, int y, int *E, int *C)
{
	if (grid[y][x] == 'E')
		*E += 1;
	if (grid[y][x] == 'C')
		*C += 1;
	if (grid[y][x] == '1' || grid[y][x] == 'E')
	{
		if (grid[y][x] == 'E')
			grid[y][x] = '1';
		return (0);
	}
	else
	{
		grid[y][x] = '1';
		DFS(grid, x + 1, y, E, C);
		DFS(grid, x - 1, y, E, C);
		DFS(grid, x, y + 1, E, C);
		DFS(grid, x, y - 1, E, C);
	}
	return (1);
}

char **check_map(int argc, char **argv)
{
	char	**map;
	int		C;
	int 	fd;
	int		y;
	int		i;

	C = 0;
	i = 0;
	y = 0;
	fd = open(argv[1], O_RDONLY);
	if (!(argc == 2) || !(fd) || !(valid_name(argv[1], ".ber", 4)))
		return (NULL);
	map = malloc(sizeof(char *) * (map_size(argv[1]) + 1));
	if (!(map))
		return (NULL);
	while ((map[y] = get_next_line(fd)))
	{
		if (ft_strlen(map[y]) < 2 || (y != 0 && ((ft_strlen(map[y - 1]) != ft_strlen(map[y]) && ft_strchr(map[y], '\n')) || (ft_strlen(map[y - 1]) != (ft_strlen(map[y]) + 1) && !(ft_strchr(map[y], '\n'))))))
			return (NULL);
		y++;
	}
	if (f_l_line(map, y) && mid_line(map, y) && PEC(map, &C) && FFL(map, argv[1], C))
		return (map);
	return (NULL);
}

//free before return(NULL);