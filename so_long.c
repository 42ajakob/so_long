/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 02:22:46 by ajakob            #+#    #+#             */
/*   Updated: 2023/06/25 01:20:49 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define WIDTH 1080
#define HEIGHT 720
#define BPP sizeof(int32_t)

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void my_keyhook(mlx_key_data_t keydata, void* param)
{
	img_t	*img = NULL;

	img = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(img->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
	{
		write(1, "<Up>\n", 5);
		img->P->instances[0].y -= 16;
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
	{
		write(1, "<Down>\n", 7);
		img->P->instances[0].y += 16;
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
	{
		write(1, "<Left>\n", 7);
		img->P->instances[0].x -= 16;
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
	{
		write(1, "<Right>\n", 8);
		img->P->instances[0].x += 16;
	}
}

int32_t	main(int argc, char **argv)
{
	img_t	img;

	if (!(print_map(argc, &*argv)))
	{
		printf("Map is not valid.\n");
		return (EXIT_FAILURE);
	}
	img.mlx = mlx_init(WIDTH, HEIGHT, "League of Pain", true);
	if (!img.mlx)
		ft_error();

	mlx_texture_t* texture = mlx_load_png("./textures/first_texture.png");
	if (!texture)
        ft_error();

	img.P = mlx_texture_to_image(img.mlx, texture);
	if (!img.P || (mlx_image_to_window(img.mlx, img.P, 0, 0) < 0))
		ft_error();
	
	img.P->instances[0].x = 540;
	img.P->instances[0].y = 360;
	mlx_key_hook(img.mlx, &my_keyhook, &img);
	mlx_loop(img.mlx);
	mlx_terminate(img.mlx);
	return (EXIT_SUCCESS);
}
