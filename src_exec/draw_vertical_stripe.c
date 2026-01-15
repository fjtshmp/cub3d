/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_stripe.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shfujita <shfujita@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 17:32:54 by yseto             #+#    #+#             */
/*   Updated: 2026/01/15 17:19:33 by shfujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_draw_step(t_game *state, t_ray *ray, t_draw *d)
{
	int	h;

	h = state->mlx.win_height;
	d->step = (double)d->tex->height / (double)ray->line_height;
	d->tex_pos = (ray->draw_start - h / 2 + ray->line_height / 2) * d->step;
}

static int	get_tex_color(t_tex *tex, int x, int y)
{
	char	*dst;

	dst = tex->data_addr + (y * tex->line_len + x * (tex->bpp / 8));
	return (*(int *)dst);
}

void	draw_wall_column(t_game *state, t_ray *ray, t_draw *d, int x)
{
	int		y;
	int		tex_y;
	int		color;
	char	*dst;

	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		tex_y = (int)d->tex_pos & (d->tex->height - 1);
		d->tex_pos += d->step;
		color = get_tex_color(d->tex, d->tex_x, tex_y);
		if (ray->side == 1)
			color = (color >> 1) & 0x7F7F7F;
		dst = state->mlx.img_addr + (y * state->mlx.line_len + x
				* (state->mlx.bpp / 8));
		*(int *)dst = color;
		y++;
	}
}

void	draw_vertical_stripe(t_game *state, t_ray *ray, int x)
{
	t_draw	d;

	init_draw_tex(state, ray, &d);
	init_draw_step(state, ray, &d);
	draw_wall_column(state, ray, &d, x);
}
