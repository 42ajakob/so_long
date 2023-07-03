/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 02:22:46 by ajakob            #+#    #+#             */
/*   Updated: 2023/07/03 15:38:08 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	exit(EXIT_FAILURE);
}

static int	move(int y, int x, t_img *img)
{
	int		i;

	i = 0;
	if (img->map[y / 64][x / 64] == 'E' && img->i_c == 0)
	{
		mlx_close_window(img->mlx);
		img->i_mv++;
		return (i);
	}
	else if (img->map[y / 64][x / 64] != 'E' && img->map[y / 64][x / 64] != '1')
	{
		img->p->instances[0].y = y;
		img->p->instances[0].x = x;
		img->i_mv++;
		i++;
	}
	if (img->map[y / 64][x / 64] == 'C')
	{
		img->map[y / 64][x / 64] = '0';
		mlx_image_to_window(img->mlx, img->s, x, y);
		img->s->instances[img->i_s].z = 1;
		img->i_s++;
		img->i_c--;
	}
	return (i);
}

static void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_img	*img;

	img = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(img->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE
		&& move(img->p->instances[0].y - 64, img->p->instances[0].x, param))
		ft_printf("<Up %d>\n", img->i_mv);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE
		&& move(img->p->instances[0].y + 64, img->p->instances[0].x, param))
		ft_printf("<Down %d>\n", img->i_mv);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE
		&& move(img->p->instances[0].y, img->p->instances[0].x - 64, param))
		ft_printf("<Left %d>\n", img->i_mv);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE
		&& move(img->p->instances[0].y, img->p->instances[0].x + 64, param))
		ft_printf("<Right %d>\n", img->i_mv);
}

static void	tex_to_img(t_img *img)
{
	t_texture	textures;

	textures.steve = mlx_load_png("./textures/steve.png");
	textures.stone = mlx_load_png("./textures/stone.png");
	textures.dirt = mlx_load_png("./textures/dirt.png");
	textures.diamond_ore = mlx_load_png("./textures/diamond_ore.png");
	textures.crafting_table = mlx_load_png("./textures/crafting_table.png");
	img->p = mlx_texture_to_image(img->mlx, textures.steve);
	img->w = mlx_texture_to_image(img->mlx, textures.stone);
	img->s = mlx_texture_to_image(img->mlx, textures.dirt);
	img->c = mlx_texture_to_image(img->mlx, textures.diamond_ore);
	img->e = mlx_texture_to_image(img->mlx, textures.crafting_table);
	mlx_delete_texture(textures.steve);
	mlx_delete_texture(textures.stone);
	mlx_delete_texture(textures.dirt);
	mlx_delete_texture(textures.diamond_ore);
	mlx_delete_texture(textures.crafting_table);
}

int32_t	main(int argc, char **argv)
{
	t_img	img;

	img.map = check_map(argc, &*argv);
	if (!(img.map))
		ft_error("Give me a valid Minecraft map!");
	int_values(&img);
	img.mlx = mlx_init((img.x - 1) * 64, img.y * 64, "Minecraft", true);
	if (!img.mlx)
		ft_error("MLX failed! D:");
	img.y = 0;
	img.x = 0;
	img.i_mv = 0;
	tex_to_img(&img);
	print_map(&img);
	mlx_key_hook(img.mlx, &my_keyhook, &img);
	mlx_loop(img.mlx);
	mlx_terminate(img.mlx);
	free_double_ptr(img.map);
	return (EXIT_SUCCESS);
}
