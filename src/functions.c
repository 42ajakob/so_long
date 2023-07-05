/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 07:05:22 by ajakob            #+#    #+#             */
/*   Updated: 2023/07/05 09:12:01 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ffl(t_check *ch)
{
	char	**grid;

	grid = malloc(sizeof(char *) * (ch->y + 1));
	ch->y = 0;
	while (ch->map[ch->y])
	{
		grid[ch->y] = ft_strdup(ch->map[ch->y]);
		ch->y++;
	}
	grid[ch->y] = NULL;
	ch->y = 0;
	while (!(ft_strchr(grid[ch->y], 'P')))
		ch->y++;
	while (grid[ch->y][ch->x] != 'P')
		ch->x++;
	dfs(&*grid, ch->x, ch->y, ch);
	free_double_ptr(grid);
	if (ch->i_e == 0 && ch->i_c == 0)
		return (1);
	return (0);
}

int	dfs(char **grid, int x, int y, t_check *ch)
{
	if (grid[y][x] == 'E')
		ch->i_e--;
	if (grid[y][x] == 'C')
		ch->i_c--;
	if (grid[y][x] == '1' || grid[y][x] == 'E')
	{
		if (grid[y][x] == 'E')
			grid[y][x] = '1';
		return (0);
	}
	else
	{
		grid[y][x] = '1';
		dfs(grid, x + 1, y, ch);
		dfs(grid, x - 1, y, ch);
		dfs(grid, x, y + 1, ch);
		dfs(grid, x, y - 1, ch);
	}
	return (1);
}

int	rectangular(t_check *ch)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	ch->x = 0;
	while (ch->map[y])
	{
		while (ch->map[y][ch->x])
			ch->x++;
		if (y != 0 && ch->x != x && y != ch->y - 1)
			return (0);
		else if (y == ch->y - 1 && ch->x != x - 1
			&& !(ft_strchr(ch->map[y], '\n')))
			return (0);
		else if (y == ch->y - 1 && ch->x != x && ft_strchr(ch->map[y], '\n'))
			return (0);
		x = ch->x;
		ch->x = 0;
		y++;
	}
	ch->x = 0;
	return (1);
}

int	valid_name(const char *argv, const char *ber, int len)
{
	size_t	i;
	size_t	j;

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

int	map_size(const char *argv)
{
	char	*line;
	int		fd;
	int		y;

	fd = open(argv, O_RDONLY);
	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!(line))
			break ;
		free(line);
		line = NULL;
		y++;
	}
	if (y > 2)
		return (y);
	return (0);
}
