/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_ceiling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseto < yseto@student.42tokyo.jp Mail>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:33:40 by yseto             #+#    #+#             */
/*   Updated: 2026/01/06 15:42:07 by yseto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->img_addr + (y * mlx->line_len + x * (mlx->bpp / 8));
	*(int *)dst = color;
}

static void	draw_horizontal_line(t_game *state, int y, int color)
{
	int	x;
	int	width;

	width = state->mlx.win_width;
	x = 0;
	while (x < width)
	{
		put_pixel(&state->mlx, x, y, color);
		x++;
	}
}

void	draw_floor_ceiling(t_game *state)
{
	int	y;
	int	height;

	height = state->mlx.win_height;
	y = 0;
	while (y < height)
	{
		if (y < height / 2)
			draw_horizontal_line(state, y, state->ceiling.value);
		else
			draw_horizotal_line(state, y, state->floor.value);
		y++;
	}
}
