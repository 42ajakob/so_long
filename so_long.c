/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 02:22:46 by ajakob            #+#    #+#             */
/*   Updated: 2023/06/28 03:57:33 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define BPP sizeof(int32_t)

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void my_keyhook(mlx_key_data_t keydata, void* param)
{
	img_t	*img;
	int		Coll;

	img = param;
	Coll = img->Co;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(img->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE && img->map[(img->P->instances[0].y - 64) / 64][img->P->instances[0].x / 64] != '1')
	{
		if (img->map[(img->P->instances[0].y - 64) / 64][img->P->instances[0].x / 64] == 'E' && img->Co == 0)
			mlx_close_window(img->mlx);
		else if (img->map[(img->P->instances[0].y - 64) / 64][img->P->instances[0].x / 64] != 'E')
		{
			write(1, "<Up>\n", 5);
			img->P->instances[0].y -= 64;
		}
		if (img->map[img->P->instances[0].y / 64][img->P->instances[0].x / 64] == 'C')
		{
			img->map[img->P->instances[0].y / 64][img->P->instances[0].x / 64] = '0';
			if (!img->FS || (mlx_image_to_window(img->mlx, img->FS, img->P->instances[0].x, img->P->instances[0].y) < 0))
					ft_error();
			img->FS->instances[img->F_S].z = 1;
			img->F_S++;
			img->Co--;
		}
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE && img->map[(img->P->instances[0].y + 64) / 64][img->P->instances[0].x / 64] != '1')
	{
		if (img->map[(img->P->instances[0].y + 64) / 64][img->P->instances[0].x / 64] == 'E' && img->Co == 0)
			mlx_close_window(img->mlx);
		else if (img->map[(img->P->instances[0].y + 64) / 64][img->P->instances[0].x / 64] != 'E')
		{
			write(1, "<Down>\n", 7);
			img->P->instances[0].y += 64;
		}
		if (img->map[img->P->instances[0].y / 64][img->P->instances[0].x / 64] == 'C')
		{
			img->map[img->P->instances[0].y / 64][img->P->instances[0].x / 64] = '0';
			if (!img->FS || (mlx_image_to_window(img->mlx, img->FS, img->P->instances[0].x, img->P->instances[0].y) < 0))
					ft_error();
			img->FS->instances[img->F_S].z = 1;
			img->F_S++;
			img->Co--;
		}
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE && img->map[img->P->instances[0].y / 64][(img->P->instances[0].x - 64) / 64] != '1')
	{
		if (img->map[img->P->instances[0].y / 64][(img->P->instances[0].x - 64) / 64] == 'E' && img->Co == 0)
			mlx_close_window(img->mlx);
		else if (img->map[img->P->instances[0].y / 64][(img->P->instances[0].x - 64) / 64] != 'E')
		{
			write(1, "<Left>\n", 7);
			img->P->instances[0].x -= 64;
		}
		if (img->map[img->P->instances[0].y / 64][img->P->instances[0].x / 64] == 'C')
		{
			img->map[img->P->instances[0].y / 64][img->P->instances[0].x / 64] = '0';
			if (!img->FS || (mlx_image_to_window(img->mlx, img->FS, img->P->instances[0].x, img->P->instances[0].y) < 0))
					ft_error();
			img->FS->instances[img->F_S].z = 1;
			img->F_S++;
			img->Co--;
		}
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE && img->map[img->P->instances[0].y / 64][(img->P->instances[0].x + 64) / 64] != '1')
	{
		if (img->map[img->P->instances[0].y / 64][(img->P->instances[0].x + 64) / 64] == 'E' && img->Co == 0)
			mlx_close_window(img->mlx);
		else if (img->map[img->P->instances[0].y / 64][(img->P->instances[0].x + 64) / 64] != 'E')
		{
			write(1, "<Right>\n", 8);
			img->P->instances[0].x += 64;
		}
		if (img->map[img->P->instances[0].y / 64][img->P->instances[0].x / 64] == 'C')
		{
			img->map[img->P->instances[0].y / 64][img->P->instances[0].x / 64] = '0';
			if (!img->FS || (mlx_image_to_window(img->mlx, img->FS, img->P->instances[0].x, img->P->instances[0].y) < 0))
					ft_error();
			img->FS->instances[img->F_S].z = 1;
			img->F_S++;
			img->Co--;
		}
	}
}

static void print_map(void *param)
{
	img_t	*img;
	int x;
	int y;
	int	W;
	int E;
	
	img = param;
	x = 0;
	y = 0;
	W = 0;
	img->F_S = 0;
	img->Co = 0;
	E = 0;
	mlx_texture_t* steve = mlx_load_png("./textures/steve.png");
	mlx_texture_t* stone = mlx_load_png("./textures/stone.png");
	mlx_texture_t* dirt = mlx_load_png("./textures/dirt.png");
	mlx_texture_t* diamond_ore = mlx_load_png("./textures/diamond_ore.png");
	mlx_texture_t* crafting_table = mlx_load_png("./textures/crafting_table.png");
	if (!steve || !stone || !dirt || !diamond_ore || !crafting_table)
        ft_error();

	img->P = mlx_texture_to_image(img->mlx, steve);
	img->W = mlx_texture_to_image(img->mlx, stone);
	img->FS = mlx_texture_to_image(img->mlx, dirt);
	img->C = mlx_texture_to_image(img->mlx, diamond_ore);
	img->E = mlx_texture_to_image(img->mlx, crafting_table);
	while (img->map[y])
	{
		while (img->map[y][x])
		{
			if (img->map[y][x] == '1')
			{
				if (!img->W || (mlx_image_to_window(img->mlx, img->W, x * 64, y * 64) < 0))
					ft_error();
				img->W->instances[W].z = 0;
				W++;
			}
			else if (img->map[y][x] == '0')
			{
				if (!img->FS || (mlx_image_to_window(img->mlx, img->FS, x * 64, y * 64) < 0))
						ft_error();
				img->FS->instances[img->F_S].z = 0;
				img->F_S++;
			}
			else if (img->map[y][x] == 'C')
			{
				if (!img->C || (mlx_image_to_window(img->mlx, img->C, x * 64, y * 64) < 0))
						ft_error();
				img->C->instances[img->Co].z = 0;
				img->Co++;
			}
			else if (img->map[y][x] == 'P')
			{
				if (!img->P || (mlx_image_to_window(img->mlx, img->P, x * 64, y * 64) < 0) || (mlx_image_to_window(img->mlx, img->FS, x * 64, y * 64) < 0))
						ft_error();
				img->FS->instances[img->F_S].z = 0;
				img->P->instances[0].z = 2;
				img->F_S++;
			}
			else if (img->map[y][x] == 'E')
			{
				if (!img->E || (mlx_image_to_window(img->mlx, img->E, x * 64, y * 64) < 0))
						ft_error();
				img->E->instances[E].z = 0;
				E++;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

int32_t	main(int argc, char **argv)
{
	img_t	img;
	int		x;
	int		y;
	
	x = 0;
	y = 0;
	if (!(img.map = check_map(argc, &*argv)))
	{
		printf("Give me a Minecraft map!\n");
		return (EXIT_FAILURE);
	}
	while (img.map[y][x])
		x++;
	while (img.map[y])
		y++;
	img.mlx = mlx_init((x - 1) * 64, y * 64, "Minecraft", true);
	if (!img.mlx)
		ft_error();
	print_map(&img);
	mlx_key_hook(img.mlx, &my_keyhook, &img);
	mlx_loop(img.mlx);
	mlx_terminate(img.mlx);
	return (EXIT_SUCCESS);
}
