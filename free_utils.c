/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shfujita <shfujita@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:08:05 by shfujita          #+#    #+#             */
/*   Updated: 2026/01/12 16:09:04 by shfujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_parse(t_parse *p)
{
	int	i;

	if (!p || !p->lines)
		return ;
	i = 0;
	while (i < p->line_count)
	{
		free(p->lines[i]);
		i++;
	}
	free(p->lines);
	p->lines = NULL;
	p->line_count = 0;
	p->cap = 0;
	p->max_width = 0;
}

void	free_map_grid(t_game *g)
{
	int	y;

	if (!g->map.grid)
		return ;
	y = 0;
	while (y < g->map.height)
	{
		free(g->map.grid[y]);
		y++;
	}
	free(g->map.grid);
	g->map.grid = NULL;
	g->map.width = 0;
	g->map.height = 0;
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
