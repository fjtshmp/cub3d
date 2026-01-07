/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseto < yseto@student.42tokyo.jp Mail>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:27:13 by yseto             #+#    #+#             */
/*   Updated: 2026/01/06 19:10:31 by yseto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_key(int keycode, t_game *state)
{
	if (keycode == KEY_ESC)
		exit_game(state);
	if (keycode == KEY_W)
		move_forward(state);
	if (keycode == KEY_S)
		move_backward(state);
	if (keycode == KEY_A)
		move_left(state);
	if (keycode == KEY_D)
		move_right(state);
	if (keycode == KEY_LEFT)
		rotate_left(state);
	if (keycode == KEY_RIGHT)
		rotate_right(state);
	return (0);
}

int	exit_game(void *state)
{
	(void)state;
	// clean_state(state);
	exit(1);
}

int	game_loop(t_game *state)
{
	draw_floor_ceiling(state);
	cast_rays(state);
	mlx_put_image_to_window(state->mlx.mlx_ptr, state->mlx.win_ptr,
		state->mlx.img_ptr, 0, 0);
	return (0);
}

int	exec_game(t_game *state)
{
	if (load_textures(state))
		return (1);
	mlx_hook(state->mlx.win_ptr, 2, 1L << 0, handle_key, state);
	mlx_hook(state->mlx.win_ptr, 17, 0, exit_game, state);
	mlx_loop_hook(state->mlx.mlx_ptr, game_loop, state);
	mlx_loop(state->mlx.mlx_ptr);
	return (0);
}
