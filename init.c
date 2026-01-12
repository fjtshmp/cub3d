/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shfujita <shfujita@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 20:48:10 by shfujita          #+#    #+#             */
/*   Updated: 2026/01/12 20:48:11 by shfujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_color(t_color *color)
{
	color->red = 0;
	color->green = 0;
	color->blue = 0;
	color->value = 0;
}

void	init_tex(t_tex *tex)
{
	tex->file_path = NULL;
	tex->img_ptr = NULL;
	tex->data_addr = NULL;
	tex->bpp = 0;
	tex->line_len = 0;
	tex->endian = 0;
	tex->width = 0;
	tex->height = 0;
}

void	init_map(t_map *map)
{
	map->grid = NULL;
	map->width = 0;
	map->height = 0;
}

void	init_player(t_player *player)
{
	player->pos_x = 0.0;
	player->pos_y = 0.0;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
}

void	init(t_game *state)
{
	int	i;

	state->mlx.mlx_ptr = NULL;
	state->mlx.win_ptr = NULL;
	state->mlx.img_ptr = NULL;
	state->mlx.img_addr = NULL;
	state->mlx.bpp = 0;
	state->mlx.line_len = 0;
	state->mlx.endian = 0;
	state->mlx.win_width = 640;
	state->mlx.win_height = 480;
	init_map(&state->map);
	init_player(&state->player);
	i = 0;
	while (i < 4)
	{
		init_tex(&state->tex[i]);
		i++;
	}
	init_color(&state->floor);
	init_color(&state->ceiling);
}
