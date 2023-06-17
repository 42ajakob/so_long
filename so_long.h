/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:34:51 by ajakob            #+#    #+#             */
/*   Updated: 2023/06/17 19:31:00 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include "MLX42/MLX42.h"
#include "libs/libft/libft.h"
#include "libs/get_next_line/get_next_line.h"

typedef struct img_s
{
	mlx_t* 		mlx;
	mlx_image_t	*wall;
	mlx_image_t	*air;
	mlx_image_t *player;
	mlx_image_t	*colletible;
	mlx_image_t	*exit;
} img_t;

typedef struct map_s
{
	char	**map;
	int		width;
	int		height;
} map_t;

#endif