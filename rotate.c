/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseto < yseto@student.42tokyo.jp Mail>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:25:16 by yseto             #+#    #+#             */
/*   Updated: 2025/12/05 17:25:17 by yseto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_game *state)
{
	double	rot;
	double	odx;
	double	opx;

	rot = ROT_SPEED;
	odx = state->player.dir_x;
	opx = state->player.plane_x;
	state->player.dir_x = odx * cos(rot) - state->player.dir_y * sin(rot);
	state->player.dir_y = odx * sin(rot) + state->player.dir_y * cos(rot);
	state->player.plane_x = opx * cos(rot) - state->player.plane_y * sin(rot);
	state->player.plane_y = opx * sin(rot) + state->player.plane_y * cos(rot);
}

void    rotate_right(t_game *state)
{
    double  rot;
    double  odx;
    double  opx;

    rot = -ROT_SPEED;
    odx = state->player.dir_x;
    opx = state->player.plane_x;

    state->player.dir_x = odx * cos(rot) - state->player.dir_y * sin(rot);
    state->player.dir_y = odx * sin(rot) + state->player.dir_y * cos(rot);

    state->player.plane_x = opx * cos(rot) - state->player.plane_y * sin(rot);
    state->player.plane_y = opx * sin(rot) + state->player.plane_y * cos(rot);
}
