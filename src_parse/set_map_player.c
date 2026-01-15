/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shfujita <shfujita@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:19:07 by shfujita          #+#    #+#             */
/*   Updated: 2026/01/13 14:23:03 by shfujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_dir(t_game *state, char c)
{
	if (c == 'N')
	{
		state->player.dir_x = 0;
		state->player.dir_y = -1;
	}
	else if (c == 'S')
	{
		state->player.dir_x = 0;
		state->player.dir_y = 1;
	}
	else if (c == 'E')
	{
		state->player.dir_x = 1;
		state->player.dir_y = 0;
	}
	else if (c == 'W')
	{
		state->player.dir_x = -1;
		state->player.dir_y = 0;
	}
}

static void	set_plane(t_game *state, char c)
{
	const double	pn = 0.66;

	if (c == 'N')
	{
		state->player.plane_x = pn;
		state->player.plane_y = 0;
	}
	else if (c == 'S')
	{
		state->player.plane_x = -pn;
		state->player.plane_y = 0;
	}
	else if (c == 'E')
	{
		state->player.plane_x = 0;
		state->player.plane_y = pn;
	}
	else if (c == 'W')
	{
		state->player.plane_x = 0;
		state->player.plane_y = -pn;
	}
}

static void	set_pos(t_game *state, t_parse *parse, int x, int y)
{
	parse->player_count++;
	if (parse->player_count > 1)
		parse_fatal(state, parse, "multiple players in map");
	state->player.pos_x = (double)x + 0.5;
	state->player.pos_y = (double)y + 0.5;
	state->map.grid[y][x] = '0';
}

void	set_map_player(t_game *state, t_parse *parse)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (y < state->map.height)
	{
		x = 0;
		while (x < state->map.width)
		{
			c = state->map.grid[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				set_pos(state, parse, x, y);
				set_dir(state, c);
				set_plane(state, c);
			}
			x++;
		}
		y++;
	}
	if (parse->player_count != 1)
		parse_fatal(state, parse, "player not found in map");
}
