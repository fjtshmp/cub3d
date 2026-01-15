/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shfujita <shfujita@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:25:20 by yseto             #+#    #+#             */
/*   Updated: 2026/01/15 17:22:15 by shfujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_game *state)
{
	double	speed;
	double	next_x;
	double	next_y;

	speed = MOVE_SPEED;
	next_x = state->player.pos_x + state->player.dir_x * speed;
	next_y = state->player.pos_y + state->player.dir_y * speed;
	if (state->map.grid[(int)next_y][(int)state->player.pos_x] != '1')
		state->player.pos_y = next_y;
	if (state->map.grid[(int)state->player.pos_y][(int)next_x] != '1')
		state->player.pos_x = next_x;
}

void	move_backward(t_game *state)
{
	double	speed;
	double	next_x;
	double	next_y;

	speed = MOVE_SPEED;
	next_x = state->player.pos_x - state->player.dir_x * speed;
	next_y = state->player.pos_y - state->player.dir_y * speed;
	if (state->map.grid[(int)next_y][(int)state->player.pos_x] != '1')
		state->player.pos_y = next_y;
	if (state->map.grid[(int)state->player.pos_y][(int)next_x] != '1')
		state->player.pos_x = next_x;
}

void	move_right(t_game *state)
{
	double	speed;
	double	next_x;
	double	next_y;

	speed = MOVE_SPEED;
	next_x = state->player.pos_x - state->player.dir_y * speed;
	next_y = state->player.pos_y + state->player.dir_x * speed;
	if (state->map.grid[(int)next_y][(int)state->player.pos_x] != '1')
		state->player.pos_y = next_y;
	if (state->map.grid[(int)state->player.pos_y][(int)next_x] != '1')
		state->player.pos_x = next_x;
}

void	move_left(t_game *state)
{
	double	speed;
	double	next_x;
	double	next_y;

	speed = MOVE_SPEED;
	next_x = state->player.pos_x + state->player.dir_y * speed;
	next_y = state->player.pos_y - state->player.dir_x * speed;
	if (state->map.grid[(int)next_y][(int)state->player.pos_x] != '1')
		state->player.pos_y = next_y;
	if (state->map.grid[(int)state->player.pos_y][(int)next_x] != '1')
		state->player.pos_x = next_x;
}
