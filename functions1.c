/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 07:07:33 by ajakob            #+#    #+#             */
/*   Updated: 2023/06/30 07:19:09 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_to_win(mlx_image_t *ch, int *i_char, int z, t_img *img)
{
	mlx_image_to_window(img->mlx, ch, img->x * 64, img->y * 64);
	ch->instances[*i_char].z = z;
	*i_char += 1;
}

int	f_l_line(t_check *ch)
{
	while (ch->map[0][ch->x])
	{
		if (ch->map[0][ch->x] != '1' && ch->map[0][ch->x] != '\n')
			return (0);
		ch->x++;
	}
	ch->x = 0;
	while (ch->map[ch->y - 1][ch->x])
	{
		if (ch->map[ch->y - 1][ch->x] != '1'
			&& ch->map[ch->y - 1][ch->x] != '\n')
			return (0);
		ch->x++;
	}
	ch->x = 0;
	return (1);
}

void	int_values(t_img *img)
{
	img->i_p = 0;
	img->i_c = 0;
	img->i_e = 0;
	img->i_s = 0;
	img->i_w = 0;
	img->x = 0;
	img->y = 0;
	while (img->map[img->y][img->x])
		img->x++;
	while (img->map[img->y])
		img->y++;
}

void	print_map(t_img *img)
{
	while (img->map[img->y])
	{
		while (img->map[img->y][img->x])
		{
			if (img->map[img->y][img->x] == '1')
				img_to_win(img->w, &img->i_w, 0, img);
			else if (img->map[img->y][img->x] == '0')
				img_to_win(img->s, &img->i_s, 0, img);
			else if (img->map[img->y][img->x] == 'C')
				img_to_win(img->c, &img->i_c, 0, img);
			else if (img->map[img->y][img->x] == 'P')
			{
				img_to_win(img->s, &img->i_s, 0, img);
				img_to_win(img->p, &img->i_p, 2, img);
			}
			else if (img->map[img->y][img->x] == 'E')
				img_to_win(img->e, &img->i_e, 0, img);
			img->x++;
		}
		img->x = 0;
		img->y++;
	}
	img->y = 0;
}
