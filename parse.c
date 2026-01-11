#include "cub3d.h"

void	init_parse(t_parse *parse)
{
	int	i;

	parse->state = ST_CFG;
	i = 0;
	while (i < 4)
		parse->tex_set[i++] = 0;
	parse->f_set = 0;
	parse->c_set = 0;
	parse->lines = NULL;
	parse->line_count = 0;
	parse->cap = 0;
	parse->max_width = 0;
	parse->player_count = 0;
}

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

static void	free_map_grid(t_game *g)
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


static void	free_tex_paths(t_game *g)
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

static void	parse_cleanup_game_partial(t_game *g)
{
	if (!g)
		return ;
	free_tex_paths(g);
	free_map_grid(g);
}

void	parse_fatal(t_game *g, t_parse *p, const char *msg)
{
	free_parse(p);
	parse_cleanup_game_partial(g);
	if (msg)
	{
		write(2, "Error\n", 6);
		write(2, msg, (int)ft_strlen(msg));
		write(2, "\n", 1);
	}
	exit(1);
}

static void	open_map(t_game *g, t_parse *p, const char *path, int *fd)
{
	*fd = open(path, O_RDONLY);
	if (*fd < 0)
	{
		perror("open");
		parse_fatal(g, p, "failed to open .cub");
	}
}

void	parse(t_game *state, const char *path)
{
	t_parse	parse;
	int		fd;
	char	*raw;

	init_parse(&parse);
	open_map(state, &parse, path, &fd);
	raw = get_next_line(fd);
	while (raw)
	{
		parse_line(state, &parse, raw);
		raw = get_next_line(fd);
	}
	close(fd);
	parse_finalize(state, &parse);
	free_parse(&parse);
}