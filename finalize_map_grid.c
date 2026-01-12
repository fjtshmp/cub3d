/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalize_map_grid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shfujita <shfujita@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 20:27:42 by shfujita          #+#    #+#             */
/*   Updated: 2026/01/12 20:46:00 by shfujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*alloc_row(t_game *state, t_parse *parse)
{
	char	*row;
	int		i;

	row = malloc((size_t)state->map.width + 1);
	if (!row)
		parse_fatal(state, parse, "malloc");
	i = 0;
	while (i < state->map.width)
		row[i++] = ' ';
	row[state->map.width] = '\0';
	return (row);
}

static void	copy_src_to_row(t_game *state, char *row, const char *src)
{
	int	x;

	x = 0;
	while (src[x] && x < state->map.width)
	{
		row[x] = src[x];
		if (row[x] == '\t')
			row[x] = ' ';
		x++;
	}
}

void	map_finalize_grid(t_game *state, t_parse *parse)
{
	int		y;
	char	*row;

	state->map.height = parse->line_count;
	state->map.width = parse->max_width;
	state->map.grid = malloc(sizeof(char *) * (state->map.height + 1));
	if (!state->map.grid)
		parse_fatal(state, parse, "malloc");
	y = 0;
	while (y < state->map.height)
	{
		row = alloc_row(state, parse);
		copy_src_to_row(state, row, parse->lines[y]);
		state->map.grid[y] = row;
		y++;
	}
	state->map.grid[state->map.height] = NULL;
}
