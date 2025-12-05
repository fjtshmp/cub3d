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

int	game_loop(t_game *state)
{
	cast_rays(state);
	draw_floor_ceiling(state);
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
}
