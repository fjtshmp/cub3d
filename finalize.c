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

void	parse_finalize(t_game *g, t_parse *p)
{
	check_cfg(g, p);
	map_finalize_grid(g, p);
	map_set_player(g, p);
	map_validate(g, p);
}