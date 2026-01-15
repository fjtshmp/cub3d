/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shfujita <shfujita@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 13:42:25 by yseto             #+#    #+#             */
/*   Updated: 2026/01/15 17:19:21 by shfujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	perform_dda(t_game *state, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (state->map.grid[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

void	calc_wall_distance(t_game *state, t_ray *ray)
{
	if (ray->side == 0)
	{
		ray->perp_wall_dist = (ray->map_x - state->player.pos_x + (1
					- ray->step_x) / 2.0) / ray->dir_x;
	}
	else
	{
		ray->perp_wall_dist = (ray->map_y - state->player.pos_y + (1
					- ray->step_y) / 2.0) / ray->dir_y;
	}
}

void	calc_wall_height(t_game *state, t_ray *ray)
{
	int	h;

	h = state->mlx.win_height;
	ray->line_height = (int)(h / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + h / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + h / 2;
	if (ray->draw_end >= h)
		ray->draw_end = h - 1;
}

void	cast_rays(t_game *state)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < state->mlx.win_width)
	{
		init_ray(state, &ray, x);
		init_dda(state, &ray);
		perform_dda(state, &ray);
		calc_wall_distance(state, &ray);
		calc_wall_height(state, &ray);
		draw_vertical_stripe(state, &ray, x);
		x++;
	}
}
