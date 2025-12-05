/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseto < yseto@student.42tokyo.jp Mail>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 13:42:25 by yseto             #+#    #+#             */
/*   Updated: 2025/12/05 15:58:48 by yseto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_ray(t_game *state, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)WIDTH - 1;
	ray->ray_dir_x = state->player.dir_x + state->player.plane_x
		* ray->camera_x;
	ray->ray_dir_y = state->player.dir_y + state->player.plane_y
		* ray->camera_x;
	ray->map_x = (int)state->player.pos_x;
	ray->map_y = (int)state->player.pos_y;
}

void	init_dda(t_game *state, t_ray *ray)
{
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (state->player.pos_x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - state->player.pos_x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (state->player.pos_y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - state->player.pos_y)
			* ray->delta_dist_y;
	}
}

void perform_dda(t_game *game, t_ray *ray)
{
    ray->hit = 0;
    while (!ray->hit)
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
        if (game->map.grid[ray->map_y][ray->map_x] == '1')
            ray->hit = 1;
    }
}


void calc_wall_distance(t_game *game, t_ray *ray)
{
    if (ray->side == 0)
        ray->perp_wall_dist = (ray->map_x - game->player.pos_x + (1 - ray->step_x) / 2) / ray->ray_dir_x;
    else
        ray->perp_wall_dist = (ray->map_y - game->player.pos_y + (1 - ray->step_y) / 2) / ray->ray_dir_y;
}


void calc_wall_height(t_ray *ray)
{
    ray->line_height = (int)(HEIGHT / ray->perp_wall_dist);

    ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
    if (ray->draw_start < 0)
        ray->draw_start = 0;

    ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
    if (ray->draw_end >= HEIGHT)
        ray->draw_end = HEIGHT - 1;
}


void draw_vertical_stripe(t_game *game, t_ray *ray, int x)
{
    for (int y = ray->draw_start; y < ray->draw_end; y++)
    {
        my_mlx_pixel_put(&game->mlx, x, y, 0xAAAAAA); // テスト用灰色
    }
}



void	cast_rays(t_game *state)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < WIDTH)
	{
		init_ray(state, &ray, x);
		init_dda(state, &ray);
		perform_dda(state, &ray);
		calc_wall_distance(state, &ray);
		calc_wall_height(&ray);
		draw_vertical_stripe(state, &ray, x);
		x++;
	}
}
