/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_stripe_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseto < yseto@student.42tokyo.jp Mail>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:00:22 by yseto             #+#    #+#             */
/*   Updated: 2026/01/06 14:35:53 by yseto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_tex	*select_wall_texture(t_game *state, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			return (&state->tex[TEX_WE]);
		else
			return (&state->tex[TEX_EA]);
	}
	else
	{
		if (ray->dir_y < 0)
			return (&state->tex[TEX_NO]);
		else
			return (&state->tex[TEX_SO]);
	}
}

double	compute_wall_x(t_game *state, t_ray *ray)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = state->player.pos_y + ray->perp_wall_dist * ray->dir_y;
	else
		wall_x = state->player.pos_x + ray->perp_wall_dist * ray->dir_x;
	return (wall_x - floor(wall_x));
}

int	compute_tex_x(t_ray *ray, t_tex *tex, double wall_x)
{
	int	tex_x;

	tex_x = (int)(wall_x * tex->width);
	if (ray->side == 0 && ray->dir_x > 0)
		tex_x = tex->width - tex_x - 1;
	if (ray->side == 1 && ray->dir_y < 0)
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}

void	init_draw_tex(t_game *state, t_ray *ray, t_draw *d)
{
	double	wall_x;

	d->tex = select_wall_texture(state, ray);
	wall_x = compute_wall_x(state, ray);
	d->tex_x = compute_tex_x(ray, d->tex, wall_x);
}
