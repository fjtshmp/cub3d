/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shfujita <shfujita@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:08:05 by shfujita          #+#    #+#             */
/*   Updated: 2026/01/15 20:07:16 by shfujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_parse(t_parse *parse)
{
	int	i;

	if (!parse)
		return ;
	if (parse->cur_line)
		free(parse->cur_line);
	if (parse->cur_trim)
		free(parse->cur_trim);
	parse->cur_line = NULL;
	parse->cur_trim = NULL;
	if (parse->lines)
	{
		i = 0;
		while (i < parse->line_count)
		{
			free(parse->lines[i]);
			i++;
		}
		free(parse->lines);
		parse->lines = NULL;
	}
	parse->line_count = 0;
	parse->cap = 0;
	parse->max_width = 0;
}

void	free_map_grid(t_game *state)
{
	int	y;

	if (!state->map.grid)
		return ;
	y = 0;
	while (y < state->map.height)
	{
		free(state->map.grid[y]);
		y++;
	}
	free(state->map.grid);
	state->map.grid = NULL;
	state->map.width = 0;
	state->map.height = 0;
}

void	free_tex_paths(t_game *g)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(g->tex[i].file_path);
		g->tex[i].file_path = NULL;
		i++;
	}
}

void	drain_gnl_and_close(t_parse *parse)
{
	char	*tmp;

	if (parse->fd < 0)
		return ;
	while (1)
	{
		tmp = get_next_line(parse->fd);
		if (!tmp)
			break ;
		free(tmp);
	}
	close(parse->fd);
	parse->fd = -1;
}
