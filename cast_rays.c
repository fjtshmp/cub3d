/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseto < yseto@student.42tokyo.jp Mail>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 13:42:25 by yseto             #+#    #+#             */
/*   Updated: 2025/12/15 18:30:43 by yseto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	perform_dda(t_game *state, t_ray *ray)
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
