/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shfujita <shfujita@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:40:43 by shfujita          #+#    #+#             */
/*   Updated: 2026/01/13 14:23:38 by shfujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_cfg(t_game *state, t_parse *parse)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!parse->tex_set[i])
			parse_fatal(state, parse, "missing texture id (NO/SO/WE/EA)");
		i++;
	}
	if (!parse->f_set || !parse->c_set)
		parse_fatal(state, parse, "missing color (F/C)");
	if (parse->line_count == 0)
		parse_fatal(state, parse, "missing map");
}

void	finalize_parse(t_game *g, t_parse *p)
{
	check_cfg(g, p);
	finalize_map_grid(g, p);
	set_map_player(g, p);
	validate_map(g, p);
}
