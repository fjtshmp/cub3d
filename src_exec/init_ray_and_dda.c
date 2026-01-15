/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray_and_dda.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseto < yseto@student.42tokyo.jp Mail>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:58:49 by yseto             #+#    #+#             */
/*   Updated: 2026/01/06 15:32:38 by yseto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_step_x(t_game *state, t_ray *ray)
{
	if (ray->dir_x < 0)
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
}

static void	init_step_y(t_game *state, t_ray *ray)
{
	if (ray->dir_y < 0)
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

void	init_dda(t_game *state, t_ray *ray)
{
	init_step_x(state, ray);
	init_step_y(state, ray);
	ray->hit = 0;
}

void	init_ray(t_game *state, t_ray *ray, int x)
{
	t_player	*p;
	double		w;

	p = &state->player;
	w = state->mlx.win_width;
	ray->camera_x = 2.0 * x / w - 1.0;
	ray->dir_x = p->dir_x + p->plane_x * ray->camera_x;
	ray->dir_y = p->dir_y + p->plane_y * ray->camera_x;
	ray->map_x = (int)p->pos_x;
	ray->map_y = (int)p->pos_y;
	if (ray->dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1.0 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1.0 / ray->dir_y);
	ray->hit = 0;
}
