/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseto < yseto@student.42tokyo.jp Mail>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:27:07 by yseto             #+#    #+#             */
/*   Updated: 2025/12/05 17:27:08 by yseto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	load_single_texture(t_tex *tex, void *mlx_ptr)
{
	if (!tex->file_path)
	{
		print_error("Texture path is NULL");
		return (1);
	}
	tex->img_ptr = mlx_xpm_file_to_image(mlx_ptr, tex->file_path, &tex->width,
			&tex->height);
	if (!tex->img_ptr)
	{
		print_error("Texture load error.");
		return (1);
	}
	tex->data_addr = mlx_get_data_addr(tex->img_ptr, &tex->bpp, &tex->line_len,
			&tex->endian);
	if (!tex->data_addr)
	{
		print_error("Texture data_addr error.");
		return (1);
	}
	return (0);
}

int	load_textures(t_game *state)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (load_single_texture(&state->tex[i], state->mlx.mlx_ptr))
			return (1);
		i++;
	}
	return (0);
}
