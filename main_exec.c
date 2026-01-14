/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shfujita <shfujita@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:27:03 by yseto             #+#    #+#             */
/*   Updated: 2026/01/14 20:55:03 by shfujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d.h"
// #include <math.h>
// #include <mlx.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <strings.h> // bzero

// #define WIN_WIDTH 640
// #define WIN_HEIGHT 480

// static void	load_test_textures(t_game *state)
// {
// 	int		i;
// 	t_tex	*tex;

// 	i = 0;
// 	while (i < 4)
// 	{
// 		tex = &state->tex[i];
// 		tex->file_path = "wall.xpm";
// 		tex->img_ptr = mlx_xpm_file_to_image(state->mlx.mlx_ptr, tex->file_path,
// 				&tex->width, &tex->height);
// 		if (!tex->img_ptr)
// 		{
// 			printf("failed to load texture: %s\n", tex->file_path);
// 			exit(1);
// 		}
// 		tex->data_addr = mlx_get_data_addr(tex->img_ptr, &tex->bpp,
// 				&tex->line_len, &tex->endian);
// 		i++;
// 	}
// }
// static void	init_test_map(t_game *state)
// {
// 	static char	*grid[] = {"1111111", "1000001", "1011101", "1000001",
// 			"1010111", "1000001", "1111111", NULL};

// 	state->map.grid = grid;
// 	state->map.height = 7;
// 	state->map.width = 7;
// }

// int	main(void)
// {
// 	t_game	state;

// 	/* -------- 構造体をゼロ初期化 -------- */
// 	bzero(&state, sizeof(t_game));
// 	/* -------- mlx 初期化 -------- */
// 	state.mlx.win_width = WIN_WIDTH;
// 	state.mlx.win_height = WIN_HEIGHT;
// 	state.mlx.mlx_ptr = mlx_init();
// 	if (!state.mlx.mlx_ptr)
// 		return (printf("mlx_init failed\n"), 1);
// 	state.mlx.win_ptr = mlx_new_window(state.mlx.mlx_ptr, state.mlx.win_width,
// 			state.mlx.win_height, "cub3D test");
// 	if (!state.mlx.win_ptr)
// 		return (printf("mlx_new_window failed\n"), 1);
// 	state.mlx.img_ptr = mlx_new_image(state.mlx.mlx_ptr, state.mlx.win_width,
// 			state.mlx.win_height);
// 	state.mlx.img_addr = mlx_get_data_addr(state.mlx.img_ptr, &state.mlx.bpp,
// 			&state.mlx.line_len, &state.mlx.endian);
// 	/* -------- テスト用マップ -------- */
// 	init_test_map(&state);
// 	/* -------- 仮プレイヤー初期化 -------- */
// 	state.player.pos_x = 3.5;
// 	state.player.pos_y = 3.5;
// 	state.player.dir_x = -1.0;
// 	state.player.dir_y = 0.0;
// 	state.player.plane_x = 0.0;
// 	state.player.plane_y = 0.66;
// 	/* -------- 仮の床・天井色 -------- */
// 	state.floor.value = 0x444444;
// 	state.ceiling.value = 0xAAAAAA;
// 	/* -------- テクスチャ読み込み -------- */
// 	load_test_textures(&state);
// 	/* -------- ゲーム実行 -------- */
// 	exec_game(&state);
// 	mlx_loop(state.mlx.mlx_ptr);
// 	return (0);
// }

// int	main(int argc, char **argv)
// {
// 	t_game	state;

// 	if (argc != 2)
// 	{
// 		printf("Usage: %s <map.cub>\n", argv[0]);
// 		return (1);
// 	}
// 	// init(&state);
// 	// parse(&state, argv[1]);
// 	exec_game(&state);
// 	// clean_state(state);
// 	return (0);
// }
