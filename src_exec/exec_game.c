/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shfujita <shfujita@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:27:13 by yseto             #+#    #+#             */
/*   Updated: 2026/01/15 17:20:03 by shfujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_key_press(int keycode, t_game *state)
{
	if (keycode == KEY_W)
		state->keys.w = 1;
	else if (keycode == KEY_A)
		state->keys.a = 1;
	else if (keycode == KEY_S)
		state->keys.s = 1;
	else if (keycode == KEY_D)
		state->keys.d = 1;
	else if (keycode == KEY_LEFT)
		state->keys.left = 1;
	else if (keycode == KEY_RIGHT)
		state->keys.right = 1;
	else if (keycode == KEY_ESC)
		exit_game(state);
	return (0);
}

int	handle_key_release(int keycode, t_game *state)
{
	if (keycode == KEY_W)
		state->keys.w = 0;
	else if (keycode == KEY_A)
		state->keys.a = 0;
	else if (keycode == KEY_S)
		state->keys.s = 0;
	else if (keycode == KEY_D)
		state->keys.d = 0;
	else if (keycode == KEY_LEFT)
		state->keys.left = 0;
	else if (keycode == KEY_RIGHT)
		state->keys.right = 0;
	return (0);
}

int	exit_game(void *state)
{
	(void)state;
	cleanup_state(state);
	exit(1);
}

int	game_loop(t_game *state)
{
	if (state->keys.w)
		move_forward(state);
	if (state->keys.s)
		move_backward(state);
	if (state->keys.a)
		move_left(state);
	if (state->keys.d)
		move_right(state);
	if (state->keys.left)
		rotate_left(state);
	if (state->keys.right)
		rotate_right(state);
	draw_floor_ceiling(state);
	cast_rays(state);
	mlx_put_image_to_window(state->mlx.mlx_ptr, state->mlx.win_ptr,
		state->mlx.img_ptr, 0, 0);
	return (0);
}

int	exec_game(t_game *state)
{
	state->mlx.win_width = WIN_WIDTH;
	state->mlx.win_height = WIN_HEIGHT;
	state->mlx.mlx_ptr = mlx_init();
	if (!state->mlx.mlx_ptr)
		return (printf("mlx_init failed\n"), 1);
	state->mlx.win_ptr = mlx_new_window(state->mlx.mlx_ptr,
			state->mlx.win_width, state->mlx.win_height, "cub3D test");
	if (!state->mlx.win_ptr)
		return (printf("mlx_new_window failed\n"), 1);
	state->mlx.img_ptr = mlx_new_image(state->mlx.mlx_ptr, state->mlx.win_width,
			state->mlx.win_height);
	state->mlx.img_addr = mlx_get_data_addr(state->mlx.img_ptr, &state->mlx.bpp,
			&state->mlx.line_len, &state->mlx.endian);
	if (load_textures(state))
		return (1);
	mlx_hook(state->mlx.win_ptr, 2, 1L << 0, handle_key_press, state);
	mlx_hook(state->mlx.win_ptr, 3, 1L << 1, handle_key_release, state);
	mlx_hook(state->mlx.win_ptr, 17, 0, exit_game, state);
	mlx_loop_hook(state->mlx.mlx_ptr, game_loop, state);
	mlx_loop(state->mlx.mlx_ptr);
	return (0);
}
