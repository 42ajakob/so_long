/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 02:22:46 by ajakob            #+#    #+#             */
/*   Updated: 2023/06/17 19:06:47 by ajakob           ###   ########.fr       */
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

static void	hook(void *param)
{
	img_t	*img = NULL;

	img = param;
	if (mlx_is_key_down(img->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(img->mlx);
	if (mlx_is_key_down(img->mlx, MLX_KEY_UP))
		img->player->instances[0].y -= 16;
	if (mlx_is_key_down(img->mlx, MLX_KEY_DOWN))
		img->player->instances[0].y += 16;
	if (mlx_is_key_down(img->mlx, MLX_KEY_LEFT))
		img->player->instances[0].x -= 16;
	if (mlx_is_key_down(img->mlx, MLX_KEY_RIGHT))
		img->player->instances[0].x += 16;
}



int32_t	main(void)
{
	img_t	img;

	img.mlx = mlx_init(WIDTH, HEIGHT, "League of Pain", true);
	if (!img.mlx)
		ft_error();

	mlx_texture_t* texture = mlx_load_png("./textures/first_texture.png");
	if (!texture)
        ft_error();

	img.player = mlx_texture_to_image(img.mlx, texture);
	if (!img.player || (mlx_image_to_window(img.mlx, img.player, 0, 0) < 0))
		ft_error();

	mlx_loop_hook(img.mlx, hook, &img);
	mlx_loop(img.mlx);
	mlx_terminate(img.mlx);
	return (EXIT_SUCCESS);
}
