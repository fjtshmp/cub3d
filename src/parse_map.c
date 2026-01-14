/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shfujita <shfujita@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 20:48:49 by shfujita          #+#    #+#             */
/*   Updated: 2026/01/13 16:32:34 by shfujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_map_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ' || c == '\t');
}

int	is_map_line(const char *line)
{
	int	has_tile;

	if (!line || !*line)
		return (0);
	has_tile = 0;
	while (*line)
	{
		if (!is_map_char(*line))
			return (0);
		if (*line == '0' || *line == '1' || *line == 'N' || *line == 'S'
			|| *line == 'E' || *line == 'W')
			has_tile = 1;
		line++;
	}
	return (has_tile);
}

static void	check_floor_surrounded(t_game *state, t_parse *parse, int y, int x)
{
	if (y <= 0 || x <= 0 || y >= state->map.height - 1 || x >= state->map.width
		- 1)
		parse_fatal(state, parse, "map not closed (floor on border)");
	if (state->map.grid[y - 1][x] == ' ' || state->map.grid[y + 1][x] == ' '
		|| state->map.grid[y][x - 1] == ' ' || state->map.grid[y][x + 1] == ' ')
		parse_fatal(state, parse, "map not closed (floor touches void)");
}

void	validate_map(t_game *state, t_parse *parse)
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
			if (!(c == '0' || c == '1' || c == ' '))
				parse_fatal(state, parse, "invalid char in map");
			if (c == '0')
				check_floor_surrounded(state, parse, y, x);
			x++;
		}
		y++;
	}
}
