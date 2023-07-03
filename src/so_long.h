/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:34:51 by ajakob            #+#    #+#             */
/*   Updated: 2023/07/03 16:42:09 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include "MLX42/MLX42.h"
# include "../libs/libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"

typedef struct img_s
{
	mlx_t		*mlx;
	char		**map;
	mlx_image_t	*p;
	mlx_image_t	*c;
	mlx_image_t	*e;
	mlx_image_t	*w;
	mlx_image_t	*s;
	int			i_p;
	int			i_c;
	int			i_e;
	int			i_w;
	int			i_s;
	int			x;
	int			y;
	int			i_mv;
}	t_img;

typedef struct texture_s
{
	mlx_texture_t	*steve;
	mlx_texture_t	*stone;
	mlx_texture_t	*dirt;
	mlx_texture_t	*diamond_ore;
	mlx_texture_t	*crafting_table;
}	t_texture;

typedef struct check_s
{
	char	**map;
	int		i_c;
	int		i_e;
	int		x;
	int		y;
}	t_check;

char	*get_next_line(int fd);
char	**check_map(int argc, char **argv);
int		dfs(char **grid, int x, int y, t_check *ch);
void	free_double_ptr(char **ptr);
int		ffl(t_check *ch);
int		rectangular(t_check *ch);
int		f_l_line(t_check *ch);
int		map_size(const char *argv);
int		valid_name(const char *argv, const char *ber, int len);
void	int_values(t_img *img);
void	print_map(t_img *img);
void	img_to_win(mlx_image_t *ch, int *i_char, int z, t_img *img);

#endif