/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 03:26:49 by ajakob            #+#    #+#             */
/*   Updated: 2023/06/30 07:10:53 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	mid_line(char **map, int last_y)
{
	int		x;
	int		y;

	x = 0;
	y = 1;
	while (map[y] != map[last_y - 1])
	{
		if (!(map[y][ft_strlen(map[y]) - 1] == '\n'
			&& map[y][ft_strlen(map[y]) - 2] == '1' && map[y][0] == '1'))
			return (0);
		while (map[y][x])
		{
			if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != 'C'
				&& map[y][x] != 'E' && map[y][x] != 'P' && map[y][x] != '\n')
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

static int	pec(t_check	*ch)
{
	int	i_p;

	i_p = 0;
	ch->i_e = 0;
	ch->i_c = 0;
	ch->x = 0;
	ch->y = 0;
	while (ch->map[ch->y])
	{
		while (ch->map[ch->y][ch->x])
		{
			if (ch->map[ch->y][ch->x] == 'P')
				i_p++;
			if (ch->map[ch->y][ch->x] == 'E')
				ch->i_e++;
			if (ch->map[ch->y][ch->x] == 'C')
				ch->i_c++;
			ch->x++;
		}
		ch->x = 0;
		ch->y++;
	}
	if (i_p == 1 && ch->i_e == 1 && ch->i_c > 0)
		return (1);
	return (0);
}

void	free_double_ptr(char **ptr)
{
	int	i;

	i = 0;
	while (ptr && ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

static int	unlogical_function_for_norminette(t_check *ch, int fd)
{
	ch->map[ch->y] = get_next_line(fd);
	if (ch->map[ch->y] == NULL)
		return (0);
	return (1);
}

char	**check_map(int argc, char **argv)
{
	t_check	ch;
	int		fd;

	ch.y = 0;
	fd = open(argv[1], O_RDONLY);
	if (argc != 2 || !(fd) || !(valid_name(argv[1], ".ber", 4)))
		return (NULL);
	ch.map = ft_calloc((map_size(argv[1]) + 1), sizeof(char *));
	if (!(ch.map))
		return (NULL);
	ch.map[map_size(argv[1]) + 1] = NULL;
	while (unlogical_function_for_norminette(&ch, fd))
		ch.y++;
	if (ch.y > 2 && rectangular(&ch) && f_l_line(&ch)
		&& mid_line(ch.map, ch.y) && pec(&ch) && ffl(&ch))
		return (ch.map);
	return (free_double_ptr(ch.map), NULL);
}
